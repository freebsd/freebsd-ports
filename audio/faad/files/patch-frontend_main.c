
$FreeBSD$

--- frontend/main.c.orig
+++ frontend/main.c
@@ -137,6 +137,31 @@
 		b->bytes_into_buffer = 0;
 }
 
+static void lookforheader(aac_buffer *b)
+{
+  int i = 0;
+	while (!b->at_eof ) 
+	{
+       		if (b->bytes_into_buffer > 4)
+        	{
+		    if( ((b->buffer[0+i] == 0xff) && ((b->buffer[1+i] & 0xf6) == 0xf0)) ||
+       			 (b->buffer[0+i] == 'A'    && b->buffer[1+i] == 'D' && b->buffer[2+i] == 'I' && b->buffer[3+i] == 'F'))
+			{
+				fill_buffer(b);
+				break;
+			} else {
+				i++;
+    				b->file_offset       += 1;
+    				b->bytes_consumed    += 1;
+    				b->bytes_into_buffer -= 1;
+			}
+		} else {
+			fill_buffer(b);
+			i = 0;
+		}
+	}
+}
+
 static int adts_sample_rates[] = {96000,88200,64000,48000,44100,32000,24000,22050,16000,12000,11025,8000,7350,0,0,0};
 
 static int adts_parse(aac_buffer *b, int *bitrate, float *length)
@@ -424,6 +449,8 @@
     float length = 0;
 
     int first_time = 1;
+    int retval;
+    int streaminput = 0;
 
     aac_buffer b;
 
@@ -439,17 +466,39 @@
         }
     }
 
-    b.infile = fopen(aacfile, "rb");
-    if (b.infile == NULL)
+    if (0 == strcmp(aacfile, "-"))
     {
-        /* unable to open file */
-        faad_fprintf(stderr, "Error opening file: %s\n", aacfile);
-        return 1;
+	b.infile = stdin;
+#ifdef _WIN32
+        setmode(fileno(stdin), O_BINARY);
+#endif
+
+    } else 
+    {
+    	b.infile = fopen(aacfile, "rb");
+    	if (b.infile == NULL)
+    	{
+    	    /* unable to open file */
+    	    faad_fprintf(stderr, "Error opening file: %s\n", aacfile);
+    	    return 1;
+    	}
     }
 
-    fseek(b.infile, 0, SEEK_END);
-    fileread = ftell(b.infile);
-    fseek(b.infile, 0, SEEK_SET);
+    retval = fseek(b.infile, 0, SEEK_END);
+#ifdef _WIN32
+	if (0 == strcmp(aacfile, "-")) {
+	  retval = -1;
+	}
+#endif
+    if (retval )
+    {
+	 faad_fprintf(stderr, "Input not seekable %s\n", aacfile);
+	 fileread = -1;
+         streaminput = 1;
+    } else {
+    	fileread = ftell(b.infile);
+    	fseek(b.infile, 0, SEEK_SET);
+    };
 
     if (!(b.buffer = (unsigned char*)malloc(FAAD_MIN_STREAMSIZE*MAX_CHANNELS)))
     {
@@ -494,19 +543,39 @@
 
     /* get AAC infos for printing */
     header_type = 0;
+    if (streaminput == 1 ) 
+	lookforheader(&b);
+
     if ((b.buffer[0] == 0xFF) && ((b.buffer[1] & 0xF6) == 0xF0))
     {
-        adts_parse(&b, &bitrate, &length);
-        fseek(b.infile, tagsize, SEEK_SET);
+        if (streaminput ==1)
+	{
+	    int frames, frame_length;
+	    int samplerate;
+	    float frames_per_sec, bytes_per_frame;
+	    samplerate = adts_sample_rates[(b.buffer[2]&0x3c)>>2];
+	    frame_length = ((((unsigned int)b.buffer[3] & 0x3)) << 11)
+	        | (((unsigned int)b.buffer[4]) << 3) | (b.buffer[5] >> 5);
 
-        bread = fread(b.buffer, 1, FAAD_MIN_STREAMSIZE*MAX_CHANNELS, b.infile);
-        if (bread != FAAD_MIN_STREAMSIZE*MAX_CHANNELS)
-            b.at_eof = 1;
-        else
-            b.at_eof = 0;
-        b.bytes_into_buffer = bread;
-        b.bytes_consumed = 0;
-        b.file_offset = tagsize;
+	    frames_per_sec = (float)samplerate/1024.0f;
+	    bytes_per_frame = (float)frame_length/(float)(1000);
+	    bitrate = (int)(8. * bytes_per_frame * frames_per_sec + 0.5);
+	    length = 1;
+	    faad_fprintf(stderr, "Streamed input format  samplerate %d channels %d.\n",samplerate,channels);
+
+	} else {
+		adts_parse(&b, &bitrate, &length);
+        	fseek(b.infile, tagsize, SEEK_SET);
+
+        	bread = fread(b.buffer, 1, FAAD_MIN_STREAMSIZE*MAX_CHANNELS, b.infile);
+        	if (bread != FAAD_MIN_STREAMSIZE*MAX_CHANNELS)
+        	    b.at_eof = 1;
+        	else
+        	    b.at_eof = 0;
+        	b.bytes_into_buffer = bread;
+        	b.bytes_consumed = 0;
+        	b.file_offset = tagsize;
+	}
 
         header_type = 1;
     } else if (memcmp(b.buffer, "ADIF", 4) == 0) {
@@ -538,7 +607,8 @@
         if (b.buffer)
             free(b.buffer);
         NeAACDecClose(hDecoder);
-        fclose(b.infile);
+        if (b.infile != stdin) 
+            fclose(b.infile);
         return 1;
     }
     advance_buffer(&b, bread);
@@ -564,7 +634,8 @@
     if (infoOnly)
     {
         NeAACDecClose(hDecoder);
-        fclose(b.infile);
+        if (b.infile != stdin) 
+            fclose(b.infile);
         if (b.buffer)
             free(b.buffer);
         return 0;
@@ -621,7 +692,8 @@
                     if (b.buffer)
                         free(b.buffer);
                     NeAACDecClose(hDecoder);
-                    fclose(b.infile);
+                    if (b.infile != stdin)
+                        fclose(b.infile);
                     return 0;
                 }
             } else {
@@ -662,7 +734,8 @@
         fclose(adtsFile);
     }
 
-    fclose(b.infile);
+    if (b.infile != stdin)
+        fclose(b.infile);
 
     if (!first_time && !adts_out)
         close_audio_file(aufile);
@@ -750,6 +823,11 @@
     /* initialise the callback structure */
     mp4ff_callback_t *mp4cb = malloc(sizeof(mp4ff_callback_t));
 
+    if (strcmp(mp4file, "-") == 0 ) {
+        faad_fprintf(stderr, "Cannot open stdin for MP4 input \n");
+        return 1;
+    }
+
     mp4File = fopen(mp4file, "rb");
     mp4cb->read = read_callback;
     mp4cb->seek = seek_callback;
@@ -1016,6 +1094,7 @@
     int result;
     int infoOnly = 0;
     int writeToStdio = 0;
+    int readFromStdin = 0;
     int object_type = LC;
     int def_srate = 0;
     int downMatrix = 0;
@@ -1229,15 +1308,30 @@
     }
 
     /* check for mp4 file */
-    mp4file = 0;
-    hMP4File = fopen(aacFileName, "rb");
-    if (!hMP4File)
-    {
-        faad_fprintf(stderr, "Error opening file: %s\n", aacFileName);
-        return 1;
+    if (0 == strcmp(aacFileName, "-")) {
+   	faad_fprintf(stderr, "Reading from stdin: %s\n", aacFileName);
+	readFromStdin = 1;
+	hMP4File  = stdin;
+#ifdef _WIN32
+        setmode(fileno(stdin), O_BINARY);
+#endif
+
+    } else {
+
+    	mp4file = 0;
+    	hMP4File = fopen(aacFileName, "rb");
+    	if (!hMP4File)
+    	{
+    	    faad_fprintf(stderr, "Error opening file: %s\n", aacFileName);
+    	    return 1;
+    	}
     }
+ 
     fread(header, 1, 8, hMP4File);
-    fclose(hMP4File);
+
+    if (! readFromStdin )
+      fclose(hMP4File);
+
     if (header[4] == 'f' && header[5] == 't' && header[6] == 'y' && header[7] == 'p')
         mp4file = 1;
 
@@ -1246,6 +1340,18 @@
         result = decodeMP4file(aacFileName, audioFileName, adtsFileName, writeToStdio,
             outputFormat, format, downMatrix, noGapless, infoOnly, adts_out, &length);
     } else {
+
+	if (readFromStdin == 1) {
+		ungetc(header[7],hMP4File);
+		ungetc(header[6],hMP4File);
+		ungetc(header[5],hMP4File);
+		ungetc(header[4],hMP4File);
+		ungetc(header[3],hMP4File);
+		ungetc(header[2],hMP4File);
+		ungetc(header[1],hMP4File);
+		ungetc(header[0],hMP4File);
+	}
+
         result = decodeAACfile(aacFileName, audioFileName, adtsFileName, writeToStdio,
             def_srate, object_type, outputFormat, format, downMatrix, infoOnly, adts_out,
             old_format, &length);
