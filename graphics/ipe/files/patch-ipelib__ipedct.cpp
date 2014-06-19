--- ipelib/ipedct.cpp.orig
+++ ipelib/ipedct.cpp
@@ -0,0 +1,1465 @@
+//------------------------------------------------------------------------
+// Decoding a DCT stream (JPEG image)
+// This code has been taken from Xpdf,
+// Copyright 1996-2002 Glyph & Cog, LLC
+//------------------------------------------------------------------------
+/*
+
+    This file is part of the extensible drawing editor Ipe.
+    Copyright (C) 1993-2013  Otfried Cheong
+
+    Ipe is free software; you can redistribute it and/or modify it
+    under the terms of the GNU General Public License as published by
+    the Free Software Foundation; either version 3 of the License, or
+    (at your option) any later version.
+
+    As a special exception, you have permission to link Ipe with the
+    CGAL library and distribute executables, as long as you follow the
+    requirements of the Gnu General Public License in regard to all of
+    the software in the executable aside from CGAL.
+
+    Ipe is distributed in the hope that it will be useful, but WITHOUT
+    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
+    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
+    License for more details.
+
+    You should have received a copy of the GNU General Public License
+    along with Ipe; if not, you can find it at
+    "http://www.gnu.org/copyleft/gpl.html", or write to the Free
+    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
+
+*/
+
+#include "ipebase.h"
+
+using namespace ipe;
+
+// --------------------------------------------------------------------
+
+// DCT component info
+struct DCTCompInfo {
+  int id;			// component ID
+  int hSample, vSample;		// horiz/vert sampling resolutions
+  int quantTable;		// quantization table number
+  int prevDC;			// DC coefficient accumulator
+};
+
+struct DCTScanInfo {
+  bool comp[4];	                // comp[i] is set if component i is
+				//   included in this scan
+  int numComps;			// number of components in the scan
+  int dcHuffTable[4];		// DC Huffman table numbers
+  int acHuffTable[4];		// AC Huffman table numbers
+  int firstCoeff, lastCoeff;	// first and last DCT coefficient
+  int ah, al;			// successive approximation parameters
+};
+
+// DCT Huffman decoding table
+struct DCTHuffTable {
+  uchar firstSym[17];		// first symbol for this bit length
+  ushort firstCode[17];	        // first code for this bit length
+  ushort numCodes[17];		// number of codes of this bit length
+  uchar sym[256];		// symbols
+};
+
+// --------------------------------------------------------------------
+
+class DCTStream {
+public:
+
+  DCTStream(DataSource &source);
+  ~DCTStream();
+  void reset();
+  int getChar();
+
+private:
+  DataSource &iSource;
+
+  bool progressive;		// set if in progressive mode
+  bool interleaved;		// set if in interleaved mode
+  int width, height;		// image size
+  int mcuWidth, mcuHeight;	// size of min coding unit, in data units
+  int bufWidth, bufHeight;	// frameBuf size
+  DCTCompInfo compInfo[4];	// info for each component
+  DCTScanInfo scanInfo;		// info for the current scan
+  int numComps;			// number of components in image
+  int colorXform;		// need YCbCr-to-RGB transform?
+  bool gotAdobeMarker;		// set if APP14 Adobe marker was present
+  int restartInterval;		// restart interval, in MCUs
+  uchar quantTables[4][64];	// quantization tables
+  int numQuantTables;		// number of quantization tables
+  DCTHuffTable dcHuffTables[4];	// DC Huffman tables
+  DCTHuffTable acHuffTables[4];	// AC Huffman tables
+  int numDCHuffTables;		// number of DC Huffman tables
+  int numACHuffTables;		// number of AC Huffman tables
+  uchar *rowBuf[4][32];		// buffer for one MCU (non-progressive mode)
+  int *frameBuf[4];		// buffer for frame (progressive mode)
+  int comp, x, y, dy;		// current position within image/MCU
+  int restartCtr;		// MCUs left until restart
+  int restartMarker;		// next restart marker
+  int eobRun;			// number of EOBs left in the current run
+  int inputBuf;			// input buffer for variable length codes
+  int inputBits;		// number of valid bits in input buffer
+
+  void restart();
+  bool readMCURow();
+  void readScan();
+  bool readDataUnit(DCTHuffTable *dcHuffTable,
+		    DCTHuffTable *acHuffTable,
+		    int *prevDC, int data[64]);
+  bool readProgressiveDataUnit(DCTHuffTable *dcHuffTable,
+			       DCTHuffTable *acHuffTable,
+			       int *prevDC, int data[64]);
+  void decodeImage();
+  void transformDataUnit(uchar *quantTable,
+			 int dataIn[64], uchar dataOut[64]);
+  int readHuffSym(DCTHuffTable *table);
+  int readAmp(int size);
+  int readBit();
+  bool readHeader();
+  bool readBaselineSOF();
+  bool readProgressiveSOF();
+  bool readScanInfo();
+  bool readQuantTables();
+  bool readHuffmanTables();
+  bool readRestartInterval();
+  bool readAdobeMarker();
+  bool readTrailer();
+  int readMarker();
+  int read16();
+};
+
+// --------------------------------------------------------------------
+
+// IDCT constants (20.12 fixed point format)
+#define dctCos1    4017		// cos(pi/16)
+#define dctSin1     799		// sin(pi/16)
+#define dctCos3    3406		// cos(3*pi/16)
+#define dctSin3    2276		// sin(3*pi/16)
+#define dctCos6    1567		// cos(6*pi/16)
+#define dctSin6    3784		// sin(6*pi/16)
+#define dctSqrt2   5793		// sqrt(2)
+#define dctSqrt1d2 2896		// sqrt(2) / 2
+
+// color conversion parameters (16.16 fixed point format)
+#define dctCrToR   91881	//  1.4020
+#define dctCbToG  -22553	// -0.3441363
+#define dctCrToG  -46802	// -0.71413636
+#define dctCbToB  116130	//  1.772
+
+// clip [-256,511] --> [0,255]
+#define dctClipOffset 256
+static uchar dctClip[768];
+static int dctClipInit = 0;
+
+// zig zag decode map
+static int dctZigZag[64] = {
+   0,
+   1,  8,
+  16,  9,  2,
+   3, 10, 17, 24,
+  32, 25, 18, 11, 4,
+   5, 12, 19, 26, 33, 40,
+  48, 41, 34, 27, 20, 13,  6,
+   7, 14, 21, 28, 35, 42, 49, 56,
+  57, 50, 43, 36, 29, 22, 15,
+  23, 30, 37, 44, 51, 58,
+  59, 52, 45, 38, 31,
+  39, 46, 53, 60,
+  61, 54, 47,
+  55, 62,
+  63
+};
+
+// --------------------------------------------------------------------
+
+DCTStream::DCTStream(DataSource &source)
+  : iSource(source)
+{
+  int i, j;
+
+  progressive = interleaved = false;
+  width = height = 0;
+  mcuWidth = mcuHeight = 0;
+  numComps = 0;
+  comp = 0;
+  x = y = dy = 0;
+  for (i = 0; i < 4; ++i) {
+    for (j = 0; j < 32; ++j) {
+      rowBuf[i][j] = 0;
+    }
+    frameBuf[i] = 0;
+  }
+
+  if (!dctClipInit) {
+    for (i = -256; i < 0; ++i)
+      dctClip[dctClipOffset + i] = 0;
+    for (i = 0; i < 256; ++i)
+      dctClip[dctClipOffset + i] = uchar(i);
+    for (i = 256; i < 512; ++i)
+      dctClip[dctClipOffset + i] = 255;
+    dctClipInit = 1;
+  }
+}
+
+DCTStream::~DCTStream()
+{
+  int i, j;
+  if (progressive || !interleaved) {
+    for (i = 0; i < numComps; ++i) {
+      delete [] frameBuf[i];
+    }
+  } else {
+    for (i = 0; i < numComps; ++i) {
+      for (j = 0; j < mcuHeight; ++j) {
+	delete [] rowBuf[i][j];
+      }
+    }
+  }
+}
+
+void DCTStream::reset()
+{
+  int minHSample, minVSample;
+  int i, j;
+
+  progressive = interleaved = false;
+  width = height = 0;
+  numComps = 0;
+  numQuantTables = 0;
+  numDCHuffTables = 0;
+  numACHuffTables = 0;
+  colorXform = 0;
+  gotAdobeMarker = false;
+  restartInterval = 0;
+
+  if (!readHeader()) {
+    y = height;
+    return;
+  }
+
+  // compute MCU size
+  mcuWidth = minHSample = compInfo[0].hSample;
+  mcuHeight = minVSample = compInfo[0].vSample;
+  for (i = 1; i < numComps; ++i) {
+    if (compInfo[i].hSample < minHSample)
+      minHSample = compInfo[i].hSample;
+    if (compInfo[i].vSample < minVSample)
+      minVSample = compInfo[i].vSample;
+    if (compInfo[i].hSample > mcuWidth)
+      mcuWidth = compInfo[i].hSample;
+    if (compInfo[i].vSample > mcuHeight)
+      mcuHeight = compInfo[i].vSample;
+  }
+  for (i = 0; i < numComps; ++i) {
+    compInfo[i].hSample /= minHSample;
+    compInfo[i].vSample /= minVSample;
+  }
+  mcuWidth = (mcuWidth / minHSample) * 8;
+  mcuHeight = (mcuHeight / minVSample) * 8;
+
+  // figure out color transform
+  if (!gotAdobeMarker && numComps == 3) {
+    if (compInfo[0].id == 1 && compInfo[1].id == 2 && compInfo[2].id == 3) {
+      colorXform = 1;
+    }
+  }
+
+  if (progressive || !interleaved) {
+
+    // allocate a buffer for the whole image
+    bufWidth = ((width + mcuWidth - 1) / mcuWidth) * mcuWidth;
+    bufHeight = ((height + mcuHeight - 1) / mcuHeight) * mcuHeight;
+    for (i = 0; i < numComps; ++i) {
+      frameBuf[i] = new int[bufWidth * bufHeight];
+      memset(frameBuf[i], 0, bufWidth * bufHeight * sizeof(int));
+    }
+
+    // read the image data
+    do {
+      restartMarker = 0xd0;
+      restart();
+      readScan();
+    } while (readHeader());
+
+    // decode
+    decodeImage();
+
+    // initialize counters
+    comp = 0;
+    x = 0;
+    y = 0;
+
+  } else {
+
+    // allocate a buffer for one row of MCUs
+    bufWidth = ((width + mcuWidth - 1) / mcuWidth) * mcuWidth;
+    for (i = 0; i < numComps; ++i) {
+      for (j = 0; j < mcuHeight; ++j) {
+	rowBuf[i][j] = new uchar[bufWidth];
+      }
+    }
+
+    // initialize counters
+    comp = 0;
+    x = 0;
+    y = 0;
+    dy = mcuHeight;
+
+    restartMarker = 0xd0;
+    restart();
+  }
+}
+
+int DCTStream::getChar()
+{
+  int c;
+
+  if (y >= height) {
+    return EOF;
+  }
+  if (progressive || !interleaved) {
+    c = frameBuf[comp][y * bufWidth + x];
+    if (++comp == numComps) {
+      comp = 0;
+      if (++x == width) {
+	x = 0;
+	++y;
+      }
+    }
+  } else {
+    if (dy >= mcuHeight) {
+      if (!readMCURow()) {
+	y = height;
+	return EOF;
+      }
+      comp = 0;
+      x = 0;
+      dy = 0;
+    }
+    c = rowBuf[comp][dy][x];
+    if (++comp == numComps) {
+      comp = 0;
+      if (++x == width) {
+	x = 0;
+	++y;
+	++dy;
+	if (y == height) {
+	  readTrailer();
+	}
+      }
+    }
+  }
+  return c;
+}
+
+void DCTStream::restart()
+{
+  int i;
+
+  inputBits = 0;
+  restartCtr = restartInterval;
+  for (i = 0; i < numComps; ++i) {
+    compInfo[i].prevDC = 0;
+  }
+  eobRun = 0;
+}
+
+// Read one row of MCUs from a sequential JPEG stream.
+bool DCTStream::readMCURow()
+{
+  int data1[64];
+  uchar data2[64];
+  uchar *p1, *p2;
+  int pY, pCb, pCr, pR, pG, pB;
+  int h, v, horiz, vert, hSub, vSub;
+  int x1, x2, y2, x3, y3, x4, y4, x5, y5, cc, i;
+  int c;
+
+  for (x1 = 0; x1 < width; x1 += mcuWidth) {
+
+    // deal with restart marker
+    if (restartInterval > 0 && restartCtr == 0) {
+      c = readMarker();
+      if (c != restartMarker) {
+	ipeDebug("Bad DCT data: incorrect restart marker");
+	return false;
+      }
+      if (++restartMarker == 0xd8)
+	restartMarker = 0xd0;
+      restart();
+    }
+
+    // read one MCU
+    for (cc = 0; cc < numComps; ++cc) {
+      h = compInfo[cc].hSample;
+      v = compInfo[cc].vSample;
+      horiz = mcuWidth / h;
+      vert = mcuHeight / v;
+      hSub = horiz / 8;
+      vSub = vert / 8;
+      for (y2 = 0; y2 < mcuHeight; y2 += vert) {
+	for (x2 = 0; x2 < mcuWidth; x2 += horiz) {
+	  if (!readDataUnit(&dcHuffTables[scanInfo.dcHuffTable[cc]],
+			    &acHuffTables[scanInfo.acHuffTable[cc]],
+			    &compInfo[cc].prevDC,
+			    data1)) {
+	    return false;
+	  }
+	  transformDataUnit(quantTables[compInfo[cc].quantTable],
+			    data1, data2);
+	  if (hSub == 1 && vSub == 1) {
+	    for (y3 = 0, i = 0; y3 < 8; ++y3, i += 8) {
+	      p1 = &rowBuf[cc][y2+y3][x1+x2];
+	      p1[0] = data2[i];
+	      p1[1] = data2[i+1];
+	      p1[2] = data2[i+2];
+	      p1[3] = data2[i+3];
+	      p1[4] = data2[i+4];
+	      p1[5] = data2[i+5];
+	      p1[6] = data2[i+6];
+	      p1[7] = data2[i+7];
+	    }
+	  } else if (hSub == 2 && vSub == 2) {
+	    for (y3 = 0, i = 0; y3 < 16; y3 += 2, i += 8) {
+	      p1 = &rowBuf[cc][y2+y3][x1+x2];
+	      p2 = &rowBuf[cc][y2+y3+1][x1+x2];
+	      p1[0] = p1[1] = p2[0] = p2[1] = data2[i];
+	      p1[2] = p1[3] = p2[2] = p2[3] = data2[i+1];
+	      p1[4] = p1[5] = p2[4] = p2[5] = data2[i+2];
+	      p1[6] = p1[7] = p2[6] = p2[7] = data2[i+3];
+	      p1[8] = p1[9] = p2[8] = p2[9] = data2[i+4];
+	      p1[10] = p1[11] = p2[10] = p2[11] = data2[i+5];
+	      p1[12] = p1[13] = p2[12] = p2[13] = data2[i+6];
+	      p1[14] = p1[15] = p2[14] = p2[15] = data2[i+7];
+	    }
+	  } else {
+	    i = 0;
+	    for (y3 = 0, y4 = 0; y3 < 8; ++y3, y4 += vSub) {
+	      for (x3 = 0, x4 = 0; x3 < 8; ++x3, x4 += hSub) {
+		for (y5 = 0; y5 < vSub; ++y5)
+		  for (x5 = 0; x5 < hSub; ++x5)
+		    rowBuf[cc][y2+y4+y5][x1+x2+x4+x5] = data2[i];
+		++i;
+	      }
+	    }
+	  }
+	}
+      }
+    }
+    --restartCtr;
+
+    // color space conversion
+    if (colorXform) {
+      // convert YCbCr to RGB
+      if (numComps == 3) {
+	for (y2 = 0; y2 < mcuHeight; ++y2) {
+	  for (x2 = 0; x2 < mcuWidth; ++x2) {
+	    pY = rowBuf[0][y2][x1+x2];
+	    pCb = rowBuf[1][y2][x1+x2] - 128;
+	    pCr = rowBuf[2][y2][x1+x2] - 128;
+	    pR = ((pY << 16) + dctCrToR * pCr + 32768) >> 16;
+	    rowBuf[0][y2][x1+x2] = dctClip[dctClipOffset + pR];
+	    pG = ((pY << 16) + dctCbToG * pCb + dctCrToG * pCr + 32768) >> 16;
+	    rowBuf[1][y2][x1+x2] = dctClip[dctClipOffset + pG];
+	    pB = ((pY << 16) + dctCbToB * pCb + 32768) >> 16;
+	    rowBuf[2][y2][x1+x2] = dctClip[dctClipOffset + pB];
+	  }
+	}
+      // convert YCbCrK to CMYK (K is passed through unchanged)
+      } else if (numComps == 4) {
+	for (y2 = 0; y2 < mcuHeight; ++y2) {
+	  for (x2 = 0; x2 < mcuWidth; ++x2) {
+	    pY = rowBuf[0][y2][x1+x2];
+	    pCb = rowBuf[1][y2][x1+x2] - 128;
+	    pCr = rowBuf[2][y2][x1+x2] - 128;
+	    pR = ((pY << 16) + dctCrToR * pCr + 32768) >> 16;
+	    rowBuf[0][y2][x1+x2] = uchar(255 - dctClip[dctClipOffset + pR]);
+	    pG = ((pY << 16) + dctCbToG * pCb + dctCrToG * pCr + 32768) >> 16;
+	    rowBuf[1][y2][x1+x2] = uchar(255 - dctClip[dctClipOffset + pG]);
+	    pB = ((pY << 16) + dctCbToB * pCb + 32768) >> 16;
+	    rowBuf[2][y2][x1+x2] = uchar(255 - dctClip[dctClipOffset + pB]);
+	  }
+	}
+      }
+    }
+  }
+  return true;
+}
+
+// Read one scan from a progressive or non-interleaved JPEG stream.
+void DCTStream::readScan()
+{
+  int data[64];
+  int x1, y1, dy1, x2, y2, y3, cc, i;
+  int h, v, horiz, vert, vSub;
+  int *p1;
+  int c;
+
+  if (scanInfo.numComps == 1) {
+    for (cc = 0; cc < numComps; ++cc) {
+      if (scanInfo.comp[cc]) {
+	break;
+      }
+    }
+    dy1 = mcuHeight / compInfo[cc].vSample;
+  } else {
+    dy1 = mcuHeight;
+  }
+
+  for (y1 = 0; y1 < bufHeight; y1 += dy1) {
+    for (x1 = 0; x1 < bufWidth; x1 += mcuWidth) {
+
+      // deal with restart marker
+      if (restartInterval > 0 && restartCtr == 0) {
+	c = readMarker();
+	if (c != restartMarker) {
+	  ipeDebug("Bad DCT data: incorrect restart marker");
+	  return;
+	}
+	if (++restartMarker == 0xd8) {
+	  restartMarker = 0xd0;
+	}
+	restart();
+      }
+
+      // read one MCU
+      for (cc = 0; cc < numComps; ++cc) {
+	if (!scanInfo.comp[cc]) {
+	  continue;
+	}
+
+	h = compInfo[cc].hSample;
+	v = compInfo[cc].vSample;
+	horiz = mcuWidth / h;
+	vert = mcuHeight / v;
+	// hSub = horiz / 8;
+	vSub = vert / 8;
+	for (y2 = 0; y2 < dy1; y2 += vert) {
+	  for (x2 = 0; x2 < mcuWidth; x2 += horiz) {
+
+	    // pull out the current values
+	    p1 = &frameBuf[cc][(y1+y2) * bufWidth + (x1+x2)];
+	    for (y3 = 0, i = 0; y3 < 8; ++y3, i += 8) {
+	      data[i] = p1[0];
+	      data[i+1] = p1[1];
+	      data[i+2] = p1[2];
+	      data[i+3] = p1[3];
+	      data[i+4] = p1[4];
+	      data[i+5] = p1[5];
+	      data[i+6] = p1[6];
+	      data[i+7] = p1[7];
+	      p1 += bufWidth * vSub;
+	    }
+
+	    // read one data unit
+	    if (progressive) {
+	      if (!readProgressiveDataUnit(
+		       &dcHuffTables[scanInfo.dcHuffTable[cc]],
+		       &acHuffTables[scanInfo.acHuffTable[cc]],
+		       &compInfo[cc].prevDC,
+		       data)) {
+		return;
+	      }
+	    } else {
+	      if (!readDataUnit(&dcHuffTables[scanInfo.dcHuffTable[cc]],
+				&acHuffTables[scanInfo.acHuffTable[cc]],
+				&compInfo[cc].prevDC,
+				data)) {
+		return;
+	      }
+	    }
+
+	    // add the data unit into frameBuf
+	    p1 = &frameBuf[cc][(y1+y2) * bufWidth + (x1+x2)];
+	    for (y3 = 0, i = 0; y3 < 8; ++y3, i += 8) {
+	      p1[0] = data[i];
+	      p1[1] = data[i+1];
+	      p1[2] = data[i+2];
+	      p1[3] = data[i+3];
+	      p1[4] = data[i+4];
+	      p1[5] = data[i+5];
+	      p1[6] = data[i+6];
+	      p1[7] = data[i+7];
+	      p1 += bufWidth * vSub;
+	    }
+	  }
+	}
+      }
+      --restartCtr;
+    }
+  }
+}
+
+// Read one data unit from a sequential JPEG stream.
+bool DCTStream::readDataUnit(DCTHuffTable *dcHuffTable,
+			     DCTHuffTable *acHuffTable,
+			     int *prevDC, int data[64])
+{
+  int run, size, amp;
+  int c;
+  int i, j;
+
+  if ((size = readHuffSym(dcHuffTable)) == 9999) {
+    return false;
+  }
+  if (size > 0) {
+    if ((amp = readAmp(size)) == 9999) {
+      return false;
+    }
+  } else {
+    amp = 0;
+  }
+  data[0] = *prevDC += amp;
+  for (i = 1; i < 64; ++i) {
+    data[i] = 0;
+  }
+  i = 1;
+  while (i < 64) {
+    run = 0;
+    while ((c = readHuffSym(acHuffTable)) == 0xf0 && run < 0x30) {
+      run += 0x10;
+    }
+    if (c == 9999) {
+      return false;
+    }
+    if (c == 0x00) {
+      break;
+    } else {
+      run += (c >> 4) & 0x0f;
+      size = c & 0x0f;
+      amp = readAmp(size);
+      if (amp == 9999) {
+	return false;
+      }
+      i += run;
+      j = dctZigZag[i++];
+      data[j] = amp;
+    }
+  }
+  return true;
+}
+
+// Read one data unit from a sequential JPEG stream.
+bool DCTStream::readProgressiveDataUnit(DCTHuffTable *dcHuffTable,
+					DCTHuffTable *acHuffTable,
+					int *prevDC, int data[64])
+{
+  int run, size, amp, bit, c;
+  int i, j, k;
+
+  // get the DC coefficient
+  i = scanInfo.firstCoeff;
+  if (i == 0) {
+    if (scanInfo.ah == 0) {
+      if ((size = readHuffSym(dcHuffTable)) == 9999) {
+	return false;
+      }
+      if (size > 0) {
+	if ((amp = readAmp(size)) == 9999) {
+	  return false;
+	}
+      } else {
+	amp = 0;
+      }
+      data[0] += (*prevDC += amp) << scanInfo.al;
+    } else {
+      if ((bit = readBit()) == 9999) {
+	return false;
+      }
+      data[0] += bit << scanInfo.al;
+    }
+    ++i;
+  }
+  if (scanInfo.lastCoeff == 0) {
+    return true;
+  }
+
+  // check for an EOB run
+  if (eobRun > 0) {
+    while (i <= scanInfo.lastCoeff) {
+      j = dctZigZag[i++];
+      if (data[j] != 0) {
+	if ((bit = readBit()) == EOF) {
+	  return false;
+	}
+	if (bit) {
+	  data[j] += 1 << scanInfo.al;
+	}
+      }
+    }
+    --eobRun;
+    return true;
+  }
+
+  // read the AC coefficients
+  while (i <= scanInfo.lastCoeff) {
+    if ((c = readHuffSym(acHuffTable)) == 9999) {
+      return false;
+    }
+
+    // ZRL
+    if (c == 0xf0) {
+      k = 0;
+      while (k < 16) {
+	j = dctZigZag[i++];
+	if (data[j] == 0) {
+	  ++k;
+	} else {
+	  if ((bit = readBit()) == EOF) {
+	    return false;
+	  }
+	  if (bit) {
+	    data[j] += 1 << scanInfo.al;
+	  }
+	}
+      }
+
+    // EOB run
+    } else if ((c & 0x0f) == 0x00) {
+      j = c >> 4;
+      eobRun = 0;
+      for (k = 0; k < j; ++k) {
+	if ((bit = readBit()) == EOF) {
+	  return 9999;
+	}
+	eobRun = (eobRun << 1) | bit;
+      }
+      eobRun += 1 << j;
+      while (i <= scanInfo.lastCoeff) {
+	j = dctZigZag[i++];
+	if (data[j] != 0) {
+	  if ((bit = readBit()) == EOF) {
+	    return false;
+	  }
+	  if (bit) {
+	    data[j] += 1 << scanInfo.al;
+	  }
+	}
+      }
+      --eobRun;
+      break;
+
+    // zero run and one AC coefficient
+    } else {
+      run = (c >> 4) & 0x0f;
+      size = c & 0x0f;
+      if ((amp = readAmp(size)) == 9999) {
+	return false;
+      }
+      k = 0;
+      do {
+	j = dctZigZag[i++];
+	while (data[j] != 0) {
+	  if ((bit = readBit()) == EOF) {
+	    return false;
+	  }
+	  if (bit) {
+	    data[j] += 1 << scanInfo.al;
+	  }
+	  j = dctZigZag[i++];
+	}
+	++k;
+      } while (k <= run);
+      data[j] = amp << scanInfo.al;
+    }
+  }
+
+  return true;
+}
+
+// Decode a progressive JPEG image.
+void DCTStream::decodeImage()
+{
+  int dataIn[64];
+  uchar dataOut[64];
+  uchar *quantTable;
+  int pY, pCb, pCr, pR, pG, pB;
+  int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, cc, i;
+  int h, v, horiz, vert, hSub, vSub;
+  int *p0, *p1, *p2;
+
+  for (y1 = 0; y1 < bufHeight; y1 += mcuHeight) {
+    for (x1 = 0; x1 < bufWidth; x1 += mcuWidth) {
+      for (cc = 0; cc < numComps; ++cc) {
+	quantTable = quantTables[compInfo[cc].quantTable];
+	h = compInfo[cc].hSample;
+	v = compInfo[cc].vSample;
+	horiz = mcuWidth / h;
+	vert = mcuHeight / v;
+	hSub = horiz / 8;
+	vSub = vert / 8;
+	for (y2 = 0; y2 < mcuHeight; y2 += vert) {
+	  for (x2 = 0; x2 < mcuWidth; x2 += horiz) {
+
+	    // pull out the coded data unit
+	    p1 = &frameBuf[cc][(y1+y2) * bufWidth + (x1+x2)];
+	    for (y3 = 0, i = 0; y3 < 8; ++y3, i += 8) {
+	      dataIn[i]   = p1[0];
+	      dataIn[i+1] = p1[1];
+	      dataIn[i+2] = p1[2];
+	      dataIn[i+3] = p1[3];
+	      dataIn[i+4] = p1[4];
+	      dataIn[i+5] = p1[5];
+	      dataIn[i+6] = p1[6];
+	      dataIn[i+7] = p1[7];
+	      p1 += bufWidth * vSub;
+	    }
+
+	    // transform
+	    transformDataUnit(quantTable, dataIn, dataOut);
+
+	    // store back into frameBuf, doing replication for
+	    // subsampled components
+	    p1 = &frameBuf[cc][(y1+y2) * bufWidth + (x1+x2)];
+	    if (hSub == 1 && vSub == 1) {
+	      for (y3 = 0, i = 0; y3 < 8; ++y3, i += 8) {
+		p1[0] = dataOut[i] & 0xff;
+		p1[1] = dataOut[i+1] & 0xff;
+		p1[2] = dataOut[i+2] & 0xff;
+		p1[3] = dataOut[i+3] & 0xff;
+		p1[4] = dataOut[i+4] & 0xff;
+		p1[5] = dataOut[i+5] & 0xff;
+		p1[6] = dataOut[i+6] & 0xff;
+		p1[7] = dataOut[i+7] & 0xff;
+		p1 += bufWidth;
+	      }
+	    } else if (hSub == 2 && vSub == 2) {
+	      p2 = p1 + bufWidth;
+	      for (y3 = 0, i = 0; y3 < 16; y3 += 2, i += 8) {
+		p1[0] = p1[1] = p2[0] = p2[1] = dataOut[i] & 0xff;
+		p1[2] = p1[3] = p2[2] = p2[3] = dataOut[i+1] & 0xff;
+		p1[4] = p1[5] = p2[4] = p2[5] = dataOut[i+2] & 0xff;
+		p1[6] = p1[7] = p2[6] = p2[7] = dataOut[i+3] & 0xff;
+		p1[8] = p1[9] = p2[8] = p2[9] = dataOut[i+4] & 0xff;
+		p1[10] = p1[11] = p2[10] = p2[11] = dataOut[i+5] & 0xff;
+		p1[12] = p1[13] = p2[12] = p2[13] = dataOut[i+6] & 0xff;
+		p1[14] = p1[15] = p2[14] = p2[15] = dataOut[i+7] & 0xff;
+		p1 += bufWidth * 2;
+		p2 += bufWidth * 2;
+	      }
+	    } else {
+	      i = 0;
+	      for (y3 = 0, y4 = 0; y3 < 8; ++y3, y4 += vSub) {
+		for (x3 = 0, x4 = 0; x3 < 8; ++x3, x4 += hSub) {
+		  p2 = p1 + x4;
+		  for (y5 = 0; y5 < vSub; ++y5) {
+		    for (x5 = 0; x5 < hSub; ++x5) {
+		      p2[x5] = dataOut[i] & 0xff;
+		    }
+		    p2 += bufWidth;
+		  }
+		  ++i;
+		}
+		p1 += bufWidth * vSub;
+	      }
+	    }
+	  }
+	}
+      }
+
+      // color space conversion
+      if (colorXform) {
+	// convert YCbCr to RGB
+	if (numComps == 3) {
+	  for (y2 = 0; y2 < mcuHeight; ++y2) {
+	    p0 = &frameBuf[0][(y1+y2) * bufWidth + x1];
+	    p1 = &frameBuf[1][(y1+y2) * bufWidth + x1];
+	    p2 = &frameBuf[2][(y1+y2) * bufWidth + x1];
+	    for (x2 = 0; x2 < mcuWidth; ++x2) {
+	      pY = *p0;
+	      pCb = *p1 - 128;
+	      pCr = *p2 - 128;
+	      pR = ((pY << 16) + dctCrToR * pCr + 32768) >> 16;
+	      *p0++ = dctClip[dctClipOffset + pR];
+	      pG = ((pY << 16) + dctCbToG * pCb + dctCrToG * pCr +
+		    32768) >> 16;
+	      *p1++ = dctClip[dctClipOffset + pG];
+	      pB = ((pY << 16) + dctCbToB * pCb + 32768) >> 16;
+	      *p2++ = dctClip[dctClipOffset + pB];
+	    }
+	  }
+	// convert YCbCrK to CMYK (K is passed through unchanged)
+	} else if (numComps == 4) {
+	  for (y2 = 0; y2 < mcuHeight; ++y2) {
+	    p0 = &frameBuf[0][(y1+y2) * bufWidth + x1];
+	    p1 = &frameBuf[1][(y1+y2) * bufWidth + x1];
+	    p2 = &frameBuf[2][(y1+y2) * bufWidth + x1];
+	    for (x2 = 0; x2 < mcuWidth; ++x2) {
+	      pY = *p0;
+	      pCb = *p1 - 128;
+	      pCr = *p2 - 128;
+	      pR = ((pY << 16) + dctCrToR * pCr + 32768) >> 16;
+	      *p0++ = 255 - dctClip[dctClipOffset + pR];
+	      pG = ((pY << 16) + dctCbToG * pCb + dctCrToG * pCr +
+		    32768) >> 16;
+	      *p1++ = 255 - dctClip[dctClipOffset + pG];
+	      pB = ((pY << 16) + dctCbToB * pCb + 32768) >> 16;
+	      *p2++ = 255 - dctClip[dctClipOffset + pB];
+	    }
+	  }
+	}
+      }
+    }
+  }
+}
+
+// Transform one data unit -- this performs the dequantization and
+// IDCT steps.  This IDCT algorithm is taken from:
+//   Christoph Loeffler, Adriaan Ligtenberg, George S. Moschytz,
+//   "Practical Fast 1-D DCT Algorithms with 11 Multiplications",
+//   IEEE Intl. Conf. on Acoustics, Speech & Signal Processing, 1989,
+//   988-991.
+// The stage numbers mentioned in the comments refer to Figure 1 in this
+// paper.
+void DCTStream::transformDataUnit(uchar *quantTable,
+				  int dataIn[64], uchar dataOut[64])
+{
+  int v0, v1, v2, v3, v4, v5, v6, v7, t;
+  int *p;
+  int i;
+
+  // dequant
+  for (i = 0; i < 64; ++i) {
+    dataIn[i] *= quantTable[i];
+  }
+
+  // inverse DCT on rows
+  for (i = 0; i < 64; i += 8) {
+    p = dataIn + i;
+
+    // check for all-zero AC coefficients
+    if (p[1] == 0 && p[2] == 0 && p[3] == 0 &&
+	p[4] == 0 && p[5] == 0 && p[6] == 0 && p[7] == 0) {
+      t = (dctSqrt2 * p[0] + 512) >> 10;
+      p[0] = t;
+      p[1] = t;
+      p[2] = t;
+      p[3] = t;
+      p[4] = t;
+      p[5] = t;
+      p[6] = t;
+      p[7] = t;
+      continue;
+    }
+
+    // stage 4
+    v0 = (dctSqrt2 * p[0] + 128) >> 8;
+    v1 = (dctSqrt2 * p[4] + 128) >> 8;
+    v2 = p[2];
+    v3 = p[6];
+    v4 = (dctSqrt1d2 * (p[1] - p[7]) + 128) >> 8;
+    v7 = (dctSqrt1d2 * (p[1] + p[7]) + 128) >> 8;
+    v5 = p[3] << 4;
+    v6 = p[5] << 4;
+
+    // stage 3
+    t = (v0 - v1+ 1) >> 1;
+    v0 = (v0 + v1 + 1) >> 1;
+    v1 = t;
+    t = (v2 * dctSin6 + v3 * dctCos6 + 128) >> 8;
+    v2 = (v2 * dctCos6 - v3 * dctSin6 + 128) >> 8;
+    v3 = t;
+    t = (v4 - v6 + 1) >> 1;
+    v4 = (v4 + v6 + 1) >> 1;
+    v6 = t;
+    t = (v7 + v5 + 1) >> 1;
+    v5 = (v7 - v5 + 1) >> 1;
+    v7 = t;
+
+    // stage 2
+    t = (v0 - v3 + 1) >> 1;
+    v0 = (v0 + v3 + 1) >> 1;
+    v3 = t;
+    t = (v1 - v2 + 1) >> 1;
+    v1 = (v1 + v2 + 1) >> 1;
+    v2 = t;
+    t = (v4 * dctSin3 + v7 * dctCos3 + 2048) >> 12;
+    v4 = (v4 * dctCos3 - v7 * dctSin3 + 2048) >> 12;
+    v7 = t;
+    t = (v5 * dctSin1 + v6 * dctCos1 + 2048) >> 12;
+    v5 = (v5 * dctCos1 - v6 * dctSin1 + 2048) >> 12;
+    v6 = t;
+
+    // stage 1
+    p[0] = v0 + v7;
+    p[7] = v0 - v7;
+    p[1] = v1 + v6;
+    p[6] = v1 - v6;
+    p[2] = v2 + v5;
+    p[5] = v2 - v5;
+    p[3] = v3 + v4;
+    p[4] = v3 - v4;
+  }
+
+  // inverse DCT on columns
+  for (i = 0; i < 8; ++i) {
+    p = dataIn + i;
+
+    // check for all-zero AC coefficients
+    if (p[1*8] == 0 && p[2*8] == 0 && p[3*8] == 0 &&
+	p[4*8] == 0 && p[5*8] == 0 && p[6*8] == 0 && p[7*8] == 0) {
+      t = (dctSqrt2 * dataIn[i+0] + 8192) >> 14;
+      p[0*8] = t;
+      p[1*8] = t;
+      p[2*8] = t;
+      p[3*8] = t;
+      p[4*8] = t;
+      p[5*8] = t;
+      p[6*8] = t;
+      p[7*8] = t;
+      continue;
+    }
+
+    // stage 4
+    v0 = (dctSqrt2 * p[0*8] + 2048) >> 12;
+    v1 = (dctSqrt2 * p[4*8] + 2048) >> 12;
+    v2 = p[2*8];
+    v3 = p[6*8];
+    v4 = (dctSqrt1d2 * (p[1*8] - p[7*8]) + 2048) >> 12;
+    v7 = (dctSqrt1d2 * (p[1*8] + p[7*8]) + 2048) >> 12;
+    v5 = p[3*8];
+    v6 = p[5*8];
+
+    // stage 3
+    t = (v0 - v1 + 1) >> 1;
+    v0 = (v0 + v1 + 1) >> 1;
+    v1 = t;
+    t = (v2 * dctSin6 + v3 * dctCos6 + 2048) >> 12;
+    v2 = (v2 * dctCos6 - v3 * dctSin6 + 2048) >> 12;
+    v3 = t;
+    t = (v4 - v6 + 1) >> 1;
+    v4 = (v4 + v6 + 1) >> 1;
+    v6 = t;
+    t = (v7 + v5 + 1) >> 1;
+    v5 = (v7 - v5 + 1) >> 1;
+    v7 = t;
+
+    // stage 2
+    t = (v0 - v3 + 1) >> 1;
+    v0 = (v0 + v3 + 1) >> 1;
+    v3 = t;
+    t = (v1 - v2 + 1) >> 1;
+    v1 = (v1 + v2 + 1) >> 1;
+    v2 = t;
+    t = (v4 * dctSin3 + v7 * dctCos3 + 2048) >> 12;
+    v4 = (v4 * dctCos3 - v7 * dctSin3 + 2048) >> 12;
+    v7 = t;
+    t = (v5 * dctSin1 + v6 * dctCos1 + 2048) >> 12;
+    v5 = (v5 * dctCos1 - v6 * dctSin1 + 2048) >> 12;
+    v6 = t;
+
+    // stage 1
+    p[0*8] = v0 + v7;
+    p[7*8] = v0 - v7;
+    p[1*8] = v1 + v6;
+    p[6*8] = v1 - v6;
+    p[2*8] = v2 + v5;
+    p[5*8] = v2 - v5;
+    p[3*8] = v3 + v4;
+    p[4*8] = v3 - v4;
+  }
+
+  // convert to 8-bit integers
+  for (i = 0; i < 64; ++i) {
+    dataOut[i] = dctClip[dctClipOffset + 128 + ((dataIn[i] + 8) >> 4)];
+  }
+}
+
+int DCTStream::readHuffSym(DCTHuffTable *table)
+{
+  ushort code;
+  int bit;
+  int codeBits;
+
+  code = 0;
+  codeBits = 0;
+  do {
+    // add a bit to the code
+    if ((bit = readBit()) == EOF)
+      return 9999;
+    code = ushort((code << 1) + bit);
+    ++codeBits;
+
+    // look up code
+    if (code - table->firstCode[codeBits] < table->numCodes[codeBits]) {
+      code -= table->firstCode[codeBits];
+      return table->sym[table->firstSym[codeBits] + code];
+    }
+  } while (codeBits < 16);
+
+  ipeDebug("Bad Huffman code in DCT stream");
+  return 9999;
+}
+
+int DCTStream::readAmp(int size)
+{
+  int amp, bit;
+  int bits;
+
+  amp = 0;
+  for (bits = 0; bits < size; ++bits) {
+    if ((bit = readBit()) == EOF)
+      return 9999;
+    amp = (amp << 1) + bit;
+  }
+  if (amp < (1 << (size - 1)))
+    amp -= (1 << size) - 1;
+  return amp;
+}
+
+int DCTStream::readBit()
+{
+  int bit;
+  int c, c2;
+
+  if (inputBits == 0) {
+    if ((c = iSource.getChar()) == EOF)
+      return EOF;
+    if (c == 0xff) {
+      do {
+	c2 = iSource.getChar();
+      } while (c2 == 0xff);
+      if (c2 != 0x00) {
+	ipeDebug("Bad DCT data: missing 00 after ff");
+	return EOF;
+      }
+    }
+    inputBuf = c;
+    inputBits = 8;
+  }
+  bit = (inputBuf >> (inputBits - 1)) & 1;
+  --inputBits;
+  return bit;
+}
+
+bool DCTStream::readHeader()
+{
+  bool doScan;
+  int n;
+  int c;
+  int i;
+
+  // read headers
+  doScan = false;
+  while (!doScan) {
+    c = readMarker();
+    switch (c) {
+    case 0xc0:			// SOF0
+      if (!readBaselineSOF()) {
+	return false;
+      }
+      break;
+    case 0xc2:			// SOF2
+      if (!readProgressiveSOF()) {
+	return false;
+      }
+      break;
+    case 0xc4:			// DHT
+      if (!readHuffmanTables()) {
+	return false;
+      }
+      break;
+    case 0xd8:			// SOI
+      break;
+    case 0xd9:			// EOI
+      return false;
+    case 0xda:			// SOS
+      if (!readScanInfo()) {
+	return false;
+      }
+      doScan = true;
+      break;
+    case 0xdb:			// DQT
+      if (!readQuantTables()) {
+	return false;
+      }
+      break;
+    case 0xdd:			// DRI
+      if (!readRestartInterval()) {
+	return false;
+      }
+      break;
+    case 0xee:			// APP14
+      if (!readAdobeMarker()) {
+	return false;
+      }
+      break;
+    case EOF:
+      ipeDebug("Bad DCT header");
+      return false;
+    default:
+      // skip APPn / COM / etc.
+      if (c >= 0xe0) {
+	n = read16() - 2;
+	for (i = 0; i < n; ++i) {
+	  iSource.getChar();
+	}
+      } else {
+	ipeDebug("Unknown DCT marker <%02x>", c);
+	return false;
+      }
+      break;
+    }
+  }
+
+  return true;
+}
+
+bool DCTStream::readBaselineSOF()
+{
+  (void) read16(); // length
+  int prec = iSource.getChar();
+  height = read16();
+  width = read16();
+  numComps = iSource.getChar();
+  if (prec != 8) {
+    ipeDebug("Bad DCT precision %d", prec);
+    return false;
+  }
+  for (int i = 0; i < numComps; ++i) {
+    compInfo[i].id = iSource.getChar();
+    int c = iSource.getChar();
+    compInfo[i].hSample = (c >> 4) & 0x0f;
+    compInfo[i].vSample = c & 0x0f;
+    compInfo[i].quantTable = iSource.getChar();
+  }
+  progressive = false;
+  return true;
+}
+
+bool DCTStream::readProgressiveSOF()
+{
+  (void) read16(); // length
+  int prec = iSource.getChar();
+  height = read16();
+  width = read16();
+  numComps = iSource.getChar();
+  if (prec != 8) {
+    ipeDebug("Bad DCT precision %d", prec);
+    return false;
+  }
+  for (int i = 0; i < numComps; ++i) {
+    compInfo[i].id = iSource.getChar();
+    int c = iSource.getChar();
+    compInfo[i].hSample = (c >> 4) & 0x0f;
+    compInfo[i].vSample = c & 0x0f;
+    compInfo[i].quantTable = iSource.getChar();
+  }
+  progressive = true;
+  return true;
+}
+
+bool DCTStream::readScanInfo()
+{
+  int length;
+  int id, c;
+  int i, j;
+
+  length = read16() - 2;
+  scanInfo.numComps = iSource.getChar();
+  --length;
+  if (length != 2 * scanInfo.numComps + 3) {
+    ipeDebug("Bad DCT scan info block");
+    return false;
+  }
+  interleaved = scanInfo.numComps == numComps;
+  for (j = 0; j < numComps; ++j) {
+    scanInfo.comp[j] = false;
+  }
+  for (i = 0; i < scanInfo.numComps; ++i) {
+    id = iSource.getChar();
+    for (j = 0; j < numComps; ++j) {
+      if (id == compInfo[j].id) {
+	break;
+      }
+    }
+    if (j == numComps) {
+      ipeDebug("Bad DCT component ID in scan info block");
+      return false;
+    }
+    scanInfo.comp[j] = true;
+    c = iSource.getChar();
+    scanInfo.dcHuffTable[j] = (c >> 4) & 0x0f;
+    scanInfo.acHuffTable[j] = c & 0x0f;
+  }
+  scanInfo.firstCoeff = iSource.getChar();
+  scanInfo.lastCoeff = iSource.getChar();
+  c = iSource.getChar();
+  scanInfo.ah = (c >> 4) & 0x0f;
+  scanInfo.al = c & 0x0f;
+  return true;
+}
+
+bool DCTStream::readQuantTables()
+{
+  int length;
+  int i;
+  int index;
+
+  length = read16() - 2;
+  while (length > 0) {
+    index = iSource.getChar();
+    if ((index & 0xf0) || index >= 4) {
+      ipeDebug("Bad DCT quantization table");
+      return false;
+    }
+    if (index == numQuantTables)
+      numQuantTables = index + 1;
+    for (i = 0; i < 64; ++i)
+      quantTables[index][dctZigZag[i]] = uchar(iSource.getChar());
+    length -= 65;
+  }
+  return true;
+}
+
+bool DCTStream::readHuffmanTables()
+{
+  DCTHuffTable *tbl;
+  int length;
+  int index;
+  ushort code;
+  uchar sym;
+  int i;
+  int c;
+
+  length = read16() - 2;
+  while (length > 0) {
+    index = iSource.getChar();
+    --length;
+    if ((index & 0x0f) >= 4) {
+      ipeDebug("Bad DCT Huffman table");
+      return false;
+    }
+    if (index & 0x10) {
+      index &= 0x0f;
+      if (index >= numACHuffTables)
+	numACHuffTables = index+1;
+      tbl = &acHuffTables[index];
+    } else {
+      if (index >= numDCHuffTables)
+	numDCHuffTables = index+1;
+      tbl = &dcHuffTables[index];
+    }
+    sym = 0;
+    code = 0;
+    for (i = 1; i <= 16; ++i) {
+      c = iSource.getChar();
+      tbl->firstSym[i] = sym;
+      tbl->firstCode[i] = code;
+      tbl->numCodes[i] = ushort(c);
+      sym += uchar(c);
+      code = ushort((code + c) << 1);
+    }
+    length -= 16;
+    for (i = 0; i < sym; ++i)
+      tbl->sym[i] = uchar(iSource.getChar());
+    length -= sym;
+  }
+  return true;
+}
+
+bool DCTStream::readRestartInterval()
+{
+  int length;
+
+  length = read16();
+  if (length != 4) {
+    ipeDebug("Bad DCT restart interval");
+    return false;
+  }
+  restartInterval = read16();
+  return true;
+}
+
+bool DCTStream::readAdobeMarker()
+{
+  int length, i;
+  char buf[12];
+  int c;
+
+  length = read16();
+  if (length < 14) {
+    goto err;
+  }
+  for (i = 0; i < 12; ++i) {
+    if ((c = iSource.getChar()) == EOF) {
+      goto err;
+    }
+    buf[i] = char(c);
+  }
+  if (::strncmp(buf, "Adobe", 5)) {
+    goto err;
+  }
+  colorXform = buf[11];
+  gotAdobeMarker = true;
+  for (i = 14; i < length; ++i) {
+    if (iSource.getChar() == EOF) {
+      goto err;
+    }
+  }
+  return true;
+
+ err:
+  ipeDebug("Bad DCT Adobe APP14 marker");
+  return false;
+}
+
+bool DCTStream::readTrailer()
+{
+  int c;
+
+  c = readMarker();
+  if (c != 0xd9) {		// EOI
+    ipeDebug("Bad DCT trailer");
+    return false;
+  }
+  return true;
+}
+
+int DCTStream::readMarker()
+{
+  int c;
+
+  do {
+    do {
+      c = iSource.getChar();
+    } while (c != 0xff);
+    do {
+      c = iSource.getChar();
+    } while (c == 0xff);
+  } while (c == 0x00);
+  return c;
+}
+
+int DCTStream::read16()
+{
+  int c1, c2;
+
+  if ((c1 = iSource.getChar()) == EOF)
+    return EOF;
+  if ((c2 = iSource.getChar()) == EOF)
+    return EOF;
+  return (c1 << 8) + c2;
+}
+
+// --------------------------------------------------------------------
+
+bool dctDecode(Buffer dctData, Buffer pixelData)
+{
+  // ipeDebug("dctDecode %d, %d", dctData.size(), pixelData.size());
+  BufferSource source(dctData);
+  DCTStream dct(source);
+  dct.reset();
+  char *p = pixelData.data();
+  int n = pixelData.size();
+  while (n--) {
+    int c = dct.getChar();
+    if (c == EOF)
+      return false;
+    *p++ = char(c);
+  }
+  return true;
+}
+
+// --------------------------------------------------------------------
