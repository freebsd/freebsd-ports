--- lib/qmp3frameheader.cc.orig	Fri Feb 23 21:29:12 2001
+++ lib/qmp3frameheader.cc	Fri Feb 13 19:17:38 2004
@@ -4,6 +4,7 @@
 
 # include "qmp3frameheader.hh"
 # include "qexception.hh"
+# include "endian.hh"
 
 #ifdef NLS
   # include <locale.h>
@@ -46,21 +47,20 @@
 
 static u_int32_t samplesPerFrame[4] = { 1152, 1152, 384, 0 };
 
-string qmp3frameheader::getLayer() { return string(layers[header->layer]);}
-u_int32_t qmp3frameheader::getSamplesPerFrame() { return samplesPerFrame[header->layer]; }
-string qmp3frameheader::getVersion() { return string(versions[header->version]);}
+string qmp3frameheader::getLayer() { return string(layers[header.layer]);}
+u_int32_t qmp3frameheader::getSamplesPerFrame() { return samplesPerFrame[header.layer]; }
+string qmp3frameheader::getVersion() { return string(versions[header.version]);}
 
 
-caddr_t qmp3frameheader::getMap() {return (caddr_t)header;}
+caddr_t qmp3frameheader::getMap() {return (caddr_t)mappedheader;}
 void qmp3frameheader::remap(caddr_t p) {
-
-  header = (struct header*)p;
+  setHeader(p);
 }
 
-u_int32_t qmp3frameheader::getSignature() {return (*(u_int32_t*)header)&MASK;}
+u_int32_t qmp3frameheader::getSignature() {return letohl(*(u_int32_t *)mappedheader)&MASK;}
 u_int32_t qmp3frameheader::getSampleRate() {
 
-  return samplerates[header->version][header->samplerate];
+  return samplerates[header.version][header.samplerate];
 }
  
 
@@ -76,28 +76,32 @@
 
 
 bool qmp3frameheader::valid (caddr_t p) {
+  struct header header;
+
+  if (p == NULL)
+	return false;
 
-  struct header *header = (struct header*)p;
+  copyHeader(&header, p);
 
-  return   ( (header->sync1      == 0xff) &&
-             (header->sync2      ==  0x7) &&
-             (header->version    != UNDEFINED_VERSION) &&
-             (header->layer      !=    0) &&
-             (header->bitrate    != 0x0f) &&
-             (header->samplerate != 0x03) &&
-             (header->emphasis   != 0x02) );
+  return   ( (header.sync1      == 0xff) &&
+             (header.sync2      ==  0x7) &&
+             (header.version    != UNDEFINED_VERSION) &&
+             (header.layer      !=    0) &&
+             (header.bitrate    != 0x0f) &&
+             (header.samplerate != 0x03) &&
+             (header.emphasis   != 0x02) );
 }
 
 
 bool qmp3frameheader::valid () {
 
-  return ! ( (header->sync1      != 0xff) ||
-             (header->sync2      !=  0x7) ||
-             (header->version    == UNDEFINED_VERSION) ||
-             (header->layer      ==    0) ||
-             (header->bitrate    == 0x0f) ||
-             (header->samplerate == 0x03) ||
-             (header->emphasis   == 0x02) );
+  return ! ( (header.sync1      != 0xff) ||
+             (header.sync2      !=  0x7) ||
+             (header.version    == UNDEFINED_VERSION) ||
+             (header.layer      ==    0) ||
+             (header.bitrate    == 0x0f) ||
+             (header.samplerate == 0x03) ||
+             (header.emphasis   == 0x02) );
 }
 
 
@@ -105,26 +109,28 @@
 
 
 bool qmp3frameheader::compatible(caddr_t p, u_int32_t signature) {
-  return ((*(u_int32_t*)p)&(MASK)) == signature;
+  return (letohl(*(u_int32_t *)p)&MASK) == signature;
 }
 
 
 u_int32_t qmp3frameheader::setNext(u_int32_t bufsize) {
+  caddr_t supposed= (char*)mappedheader+getLength();
 
-  caddr_t supposed= (char*)header+getLength();
+  setHeader(seek_header(supposed,bufsize,getSignature()));
 
-  header = (struct header*) seek_header(supposed,bufsize,getSignature());
-
-  return (char*)header-(char*)supposed;
+  return (char*)mappedheader-(char*)supposed;
 }
 
 u_int32_t qmp3frameheader::setNext(caddr_t endstream) {
 
-  caddr_t previous = (caddr_t) header;
+  caddr_t previous = (caddr_t) mappedheader;
+  caddr_t next;
+
+  next = seek_header((char*)mappedheader+getLength(),(char*)endstream-(char*)mappedheader+1,getSignature());
 
-  header = (struct header*) seek_header((char*)header+getLength(),(char*)endstream-(char*)header+1,getSignature());
+  setHeader(next);
 
-  return (char*)header-(char*)previous-getLength();
+  return (char*)mappedheader-(char*)previous-getLength();
 }
 
 
@@ -156,7 +162,59 @@
 
 qmp3frameheader::qmp3frameheader(caddr_t p, u_int32_t bufsize, u_int32_t signature) {
 
-  header = (struct header*) seek_header(p,bufsize,signature);
+  setHeader(seek_header(p,bufsize,signature));
+}
+
+
+void qmp3frameheader::setHeader(caddr_t p)
+{
+  mappedheader = (struct header *)p;
+  copyHeader(&header, p);
+}
+
+void qmp3frameheader::copyHeader(struct header *header, caddr_t p)
+{
+  unsigned char b = *(unsigned char *)p;
+
+  header->sync1 = b;
+
+  b = *(++p);
+  header->protection = b & 0x1;
+  header->layer = (b>>1) & 0x3;
+  header->version = (b>>3) & 0x3;
+  header->sync2 = (b>>5) & 0x7;
+
+  b = *(++p);
+  header->privat = b & 0x1;
+  header->padding = (b>>1) & 0x1;
+  header->samplerate = (b>>2) & 0x3;
+  header->bitrate = (b>>4) & 0xf;
+
+  b = *(++p);
+  header->emphasis = b & 0x3;
+  header->original = (b>>2) & 0x1;
+  header->copyright = (b>>3) & 0x1;
+  header->mode_extension = (b>>4) & 0x3;
+  header->channel_mode = (b>>6) & 0x3;
+}
+
+void qmp3frameheader::copyHeader(caddr_t p, struct header &header)
+{
+  *(p++) = header.sync1;
+
+  *(p++) = (header.protection |
+			header.layer << 1 |
+			header.version << 3 |
+			header.sync2 << 5);
+  *(p++) = (header.privat |
+			header.padding << 1 |
+			header.samplerate << 2 |
+			header.bitrate << 4);
+  *(p++) = (header.emphasis |
+			header.original << 2 |
+			header.copyright << 3 |
+			header.mode_extension << 4 |
+			header.channel_mode << 6);
 }
 
 
@@ -164,20 +222,20 @@
 
   switch (f) {
 
-    case SYNC1: 	return header->sync1;
-    case SYNC2: 	return header->sync2;
-    case _VERSION: 	return header->version;
-    case LAYER: 	return header->layer;
-    case PROTECTION: 	return header->protection;
-    case BITRATE: 	return header->bitrate;
-    case SAMPLERATE: 	return header->samplerate;
-    case PADDING: 	return header->padding;
-    case PRIVAT: 	return header->privat;
-    case CHANNEL_MODE: 	return header->channel_mode;
-    case MODE_EXTENSION: return header->mode_extension;
-    case COPYRIGHT: 	return header->copyright;
-    case ORIGINAL: 	return header->original;
-    case EMPHASIS: 	return header->emphasis;
+    case SYNC1: 	return header.sync1;
+    case SYNC2: 	return header.sync2;
+    case _VERSION: 	return header.version;
+    case LAYER: 	return header.layer;
+    case PROTECTION: 	return header.protection;
+    case BITRATE: 	return header.bitrate;
+    case SAMPLERATE: 	return header.samplerate;
+    case PADDING: 	return header.padding;
+    case PRIVAT: 	return header.privat;
+    case CHANNEL_MODE: 	return header.channel_mode;
+    case MODE_EXTENSION: return header.mode_extension;
+    case COPYRIGHT: 	return header.copyright;
+    case ORIGINAL: 	return header.original;
+    case EMPHASIS: 	return header.emphasis;
     default:
       throw qexception(__PRETTY_FUNCTION__,_("invalid field"));
      // i pintar el valor...
@@ -189,34 +247,35 @@
 
   switch (f) {
 
-    case SYNC1: 	header->sync1 = v; break;
-    case SYNC2: 	header->sync2 = v; break;
-    case _VERSION: 	header->version = v; break;
-    case LAYER: 	header->layer = v; break;
-    case PROTECTION: 	header->protection = v; break;
-    case BITRATE: 	header->bitrate = v; break;
-    case SAMPLERATE: 	header->samplerate = v; break;
-    case PADDING: 	header->padding = v; break;
-    case PRIVAT: 	header->privat = v; break;
-    case CHANNEL_MODE: 	header->channel_mode = v; break;
-    case MODE_EXTENSION: header->mode_extension = v; break;
-    case COPYRIGHT: 	header->copyright = v; break;
-    case ORIGINAL: 	header->original = v; break;
-    case EMPHASIS: 	header->emphasis = v; break;
+    case SYNC1: 	header.sync1 = v; break;
+    case SYNC2: 	header.sync2 = v; break;
+    case _VERSION: 	header.version = v; break;
+    case LAYER: 	header.layer = v; break;
+    case PROTECTION: 	header.protection = v; break;
+    case BITRATE: 	header.bitrate = v; break;
+    case SAMPLERATE: 	header.samplerate = v; break;
+    case PADDING: 	header.padding = v; break;
+    case PRIVAT: 	header.privat = v; break;
+    case CHANNEL_MODE: 	header.channel_mode = v; break;
+    case MODE_EXTENSION: header.mode_extension = v; break;
+    case COPYRIGHT: 	header.copyright = v; break;
+    case ORIGINAL: 	header.original = v; break;
+    case EMPHASIS: 	header.emphasis = v; break;
     default:
       throw qexception(__PRETTY_FUNCTION__,_("invalid field"));
      // i pintar el valor...
   }
+  copyHeader((caddr_t)mappedheader, header);
 }
 
 
 u_int32_t qmp3frameheader::getLength() {
  
-  if (header->layer!=LAYER3)
+  if (header.layer!=LAYER3)
     throw qexception (__PRETTY_FUNCTION__,_("layer not supported"));
    // i dir quin valor...
 
-  return (144 * getBitRate() * 1000) / getSampleRate() + header->padding;
+  return (144 * getBitRate() * 1000) / getSampleRate() + header.padding;
 }
 
 u_int32_t qmp3frameheader::getMsDuration() {
@@ -236,13 +295,13 @@
 
 u_int32_t qmp3frameheader::getBitRate() {
 
-  if (header->layer!=LAYER3)
+  if (header.layer!=LAYER3)
     throw qexception (__PRETTY_FUNCTION__,_("only layer III is supported"));
 
-  if (header->version==UNDEFINED_VERSION)
+  if (header.version==UNDEFINED_VERSION)
     throw qexception (__PRETTY_FUNCTION__,_("undefined version"));
 
-  return layer3_bitrates[header->version][header->bitrate];
+  return layer3_bitrates[header.version][header.bitrate];
 }
 
  
