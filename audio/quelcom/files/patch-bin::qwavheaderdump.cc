--- bin/qwavheaderdump.cc.orig	Fri Feb 23 21:29:12 2001
+++ bin/qwavheaderdump.cc	Fri Feb 13 19:17:38 2004
@@ -1,7 +1,15 @@
 # include <getopt.h>	// getopt
 # include <sys/types.h>	// u_int16_t, u_int32_t
 # include "qfile.hh"
+# include "qwavheader.hh"
 # include "qexception.hh"
+# include "endian.hh"
+
+/* caved in and used C's printf in a few places that don't seem to
+ * be expressible with ios
+ */
+#include <cstdio>
+#include <iostream>
 
 #ifdef NLS
   # include <locale.h>
@@ -29,15 +37,15 @@
     
   char data[4];
   u_int32_t datalength;
-};
+} __attribute__((packed));
 
 const unsigned int HEADERSIZE = sizeof(struct header);
 
 
 void usage () {
 
-  cerr.form(_(" %s: dump (and fix) wav header\n"),APPNAME);
-  cerr.form(_(" syntax: %s [option]... file...\n"),APPNAME);
+  fprintf(stderr,_(" %s: dump (and fix) wav header\n"),APPNAME);
+  fprintf(stderr,_(" syntax: %s [option]... file...\n"),APPNAME);
   cerr << _("   -F, --fix: correct header. use with care\n");
   cerr << _("   -h, --help: show this help and exit\n");
   cerr << _("   -q, --quiet: no output messages\n");
@@ -86,13 +94,14 @@
         quiet=true;
       break;
       case 'V':
-        cerr.form(_("%s - version %s - build %s\n"),APPNAME,VERSION,__DATE__);
+        cerr << APPNAME << " - " << _("version") << ' ' << VERSION
+	     << _("build") << ' ' << __DATE__ << '\n';
         return 0;
       break;      
       case '?':
       default: 
-        cerr.form(_("%s: option '%s' is not recognized or bad used\n"),
-                  APPNAME,argv[optind-1]);
+        cerr << APPNAME << ": " << _("option") << " '" << argv[optind-1]
+	     << "' " << _("is not recognized or bad used") << '\n';
         usage();
         return 1;
     } 
@@ -113,22 +122,33 @@
       qfile f(argv[optind],openmode);
       
       if (f.getSize()<HEADERSIZE) {
-        cerr.form(_("%s: '%s' has not enough room for a wav header\n"),
-                  APPNAME,f.getName().c_str());
+        cerr << APPNAME << ": '" << f.getName()
+	     << _("' has not enough room for a wav header\n");
         optind++;
         continue;
       }
 
+	  if ((int)f.getMap() % sizeof(u_int32_t) != 0) {
+		// should never happen with a mapping at offset 0, but if it does,
+		// we need to catch it rather than tossing subtle memory misread
+		// bugs.  32-bit alignment is adequate since no integer in a WAV header
+		// is longer
+		cerr << APPNAME << _(": mapping of header in '") << f.getName()
+			 << _("' is not 32-bit aligned\n");
+		optind++;
+		continue;
+	  }
+
       struct header *header = (struct header*) f.getMap();
 
       cout << f.getName() << " (" << f.getSize() << " bytes):" << endl;
 
      // the file should have an integer number of samples...
 
-      cout.form("\triff: '%.4s'\n",header->riff);
+      printf("\triff: '%.4s'\n",header->riff);
       if (strncmp(header->riff,"RIFF",4)) {
         if (!quiet) 
-          cerr.form(_("\t\triff field should be 'RIFF'\n"));
+          fprintf(stderr,_("\t\triff field should be 'RIFF'\n"));
         if (fix) {
           strncpy(header->riff,"RIFF",4);
           if (!quiet)
@@ -136,21 +156,21 @@
         }
       }
       
-      cout.form(_("\triff length: %d\n"),header->rifflength);
-      if (header->rifflength!=f.getSize()-8) {
+      printf(_("\triff length: %d\n"),letohl(header->rifflength));
+      if (letohl(header->rifflength)!=f.getSize()-8) {
         if (!quiet)
-          cerr.form(_("\t\triff length field should be %d\n"),f.getSize()-8);
+          fprintf(stderr,_("\t\triff length field should be %d\n"),f.getSize()-8);
         if (fix) {
-          header->rifflength = f.getSize()-8;
+          header->rifflength = htolel(f.getSize()-8);
           if (!quiet)
             cerr << _("\t\tfixed\n");
         }
       }
 
-      cout.form("\twave: '%.4s'\n",header->wave);
+      printf("\twave: '%.4s'\n",header->wave);
       if (strncmp(header->wave,"WAVE",4)) {
         if (!quiet) 
-          cerr.form(_("\t\twave field should be 'WAVE'\n"));
+          fprintf(stderr,_("\t\twave field should be 'WAVE'\n"));
         if (fix) {
           strncpy(header->wave,"WAVE",4);
           if (!quiet)
@@ -158,10 +178,10 @@
         }
       }
       
-      cout.form("\tfmt: '%.4s'\n",header->fmt_);
+      printf("\tfmt: '%.4s'\n",header->fmt_);
       if (strncmp(header->fmt_,"fmt ",4)) {
         if (!quiet) 
-          cerr.form(_("\t\tfmt  field should be 'fmt '\n"));
+          fprintf(stderr,_("\t\tfmt  field should be 'fmt '\n"));
         if (fix) {
           strncpy(header->fmt_,"fmt ",4);
           if (!quiet)
@@ -169,32 +189,33 @@
         }
       }
 
-      cout.form(_("\tfmt length: %d\n"),header->fmtlength);
-      if (header->fmtlength!=16) {
+      printf(_("\tfmt length: %d\n"),letohl(header->fmtlength));
+      if (letohl(header->fmtlength)!=16) {
         if (!quiet)
-          cerr.form(_("\t\tfmt length field should be %d\n"),16);
+          fprintf(stderr,_("\t\tfmt length field should be %d\n"),16);
         if (fix) {
-          header->fmtlength = 16;
+          header->fmtlength = htolel(16);
           if (!quiet)
             cerr << _("\t\tfixed\n");
         }
       }
 
-      cout.form("\tformat: %d\n",header->format);
-      if (header->format!=1) {
+      printf("\tformat: %d\n",letohs(header->format));
+      if (letohs(header->format)!=1) {
         if (!quiet)
-          cerr.form(_("\t\tformat field should 1 (pcm tag)\n"),16);
+          fprintf(stderr,_("\t\tformat field should 1 (pcm tag)\n"));
         if (fix) {
-          header->format = 1;
+          header->format = htoles(1);
           if (!quiet)
             cerr << _("\t\tfixed\n");
         }
       }
 
-      cout.form(_("\tchannels: %d\n"),header->channels);
-      if (header->channels!=2 && header->channels!=1) {
+      printf(_("\tchannels: %d\n"),letohs(header->channels));
+      if (letohs(header->channels)!=2 &&
+		  letohs(header->channels)!=1) {
         if (!quiet)
-          cerr.form(_("\t\tchannels field should be 1 (mono) or 2 (stereo)\n"));
+          fprintf(stderr,_("\t\tchannels field should be 1 (mono) or 2 (stereo)\n"));
         if (fix) {
           cerr << _("\t\tdon't know which value must be set...\n") << endl;
           if (!quiet)
@@ -202,33 +223,34 @@
         }
       }
 
-      cout.form(_("\tsample rate: %d\n"),header->samplerate);
-      if (header->samplerate>48000 || header->samplerate<8000) {
+      printf(_("\tsample rate: %d\n"),letohl(header->samplerate));
+      if (letohl(header->samplerate)>48000 ||
+		  letohl(header->samplerate)<8000) {
         if (!quiet)
-          cerr.form(_("\t\tsample rate field should be between 8000 and 48000\n"));
+          fprintf(stderr,_("\t\tsample rate field should be between 8000 and 48000\n"));
         if (fix)
           cerr << _("\t\tdon't know which value must be set...\n") << endl;
       }
 
-      cout.form(_("\tbytes/second: %d\n"),header->bytespersec);
+      printf(_("\tbytes/second: %d\n"),letohl(header->bytespersec));
 
 
-      cout.form(_("\tbytes/sample: %d\n"),header->bytespersample);
-      if (header->bytespersample!=1 &&
-          header->bytespersample!=2 &&
-          header->bytespersample!=4) {
+      printf(_("\tbytes/sample: %d\n"),letohs(header->bytespersample));
+      if (letohs(header->bytespersample)!=1 &&
+          letohs(header->bytespersample)!=2 &&
+          letohs(header->bytespersample)!=4) {
         if (!quiet)
-          cerr.form(_("\t\t bytes/sample field should be 1, 2 or 4\n"));
+          fprintf(stderr,_("\t\t bytes/sample field should be 1, 2 or 4\n"));
         if (fix)
           cerr << _("\t\tdon't know which value must be set...\n") << endl;
       }
 
-      cout.form(_("\tbits/sample: %d\n"),header->bitspersample);
+      printf(_("\tbits/sample: %d\n"),letohs(header->bitspersample));
 
-      cout.form("\tdata: '%.4s'\n",header->data);
+      printf("\tdata: '%.4s'\n",header->data);
       if (strncmp(header->data,"data",4)) {
         if (!quiet) 
-          cerr.form(_("\t\tdata field should be 'data'\n"));
+          fprintf(stderr,_("\t\tdata field should be 'data'\n"));
         if (fix) {
           strncpy(header->data,"data",4);
           if (!quiet)
@@ -236,12 +258,12 @@
         }
       }
 
-      cout.form(_("\tdata length: %d\n"),header->datalength);
-      if (header->datalength!=f.getSize()-44) {
+      printf(_("\tdata length: %d\n"),letohl(header->datalength));
+      if (letohl(header->datalength)!=f.getSize()-44) {
         if (!quiet)
-          cerr.form(_("\t\tdata length field should be %d\n"),f.getSize()-44);
+          fprintf(stderr,_("\t\tdata length field should be %d\n"),f.getSize()-44);
         if (fix) {
-          header->datalength = f.getSize()-44;
+          header->datalength = htolel(f.getSize()-44);
           if (!quiet)
             cerr << _("\t\tfixed\n");
         }
