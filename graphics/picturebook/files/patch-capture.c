--- capture.c.old	Thu Jul 27 02:15:05 2000
+++ capture.c	Thu Oct 16 07:21:39 2003
@@ -39,7 +39,7 @@
 	}
 }
 
-static void sigint(void)
+static void sigint(int dummy)
 {
 	spic_shutdown(0);
 	_exit(1);
@@ -47,31 +47,31 @@
 
 static void usage(void)
 {
-	printf("
-VAIO PCG-C1XS capture program
-Copyright 2000 tridge@linuxcare.com
-For the latest version see http://samba.org/picturebook/
-
-capture <options>
-  -o outfile       set output filename
-  -q quality       set compressed image quality (1-10  default 8)
-  -P               capture as a PPM file
-  -V captime       capture an avi video for the specified number of seconds
-  -O               turn off camera afterwards
-  -4               use 1:4 sub-sampling
-  -s               go into \"snap\" mode
-  -r rate          set framerate in frames per second
-  -j               display input from jogger/buttons etc
-  --brightness=n   set brightness
-  --contrast=n     set contrast
-  --hue=n          set hue
-  --color=n        set color
-  --sharpness=n    set sharpness
-  --agc=n          set agc
-  --picture=n      set picture
-  --explode=fname  explode a AVI file into frame.*
-  -h               show usage
-
+	printf("\n\
+VAIO PCG-C1XS capture program\n\
+Copyright 2000 tridge@linuxcare.com\n\
+For the latest version see http://samba.org/picturebook/\n\
+\n\
+capture <options>\n\
+  -o outfile       set output filename\n\
+  -q quality       set compressed image quality (1-10  default 8)\n\
+  -P               capture as a PPM file\n\
+  -V captime       capture an avi video for the specified number of seconds\n\
+  -O               turn off camera afterwards\n\
+  -4               use 1:4 sub-sampling\n\
+  -s               go into \"snap\" mode\n\
+  -r rate          set framerate in frames per second\n\
+  -j               display input from jogger/buttons etc\n\
+  --brightness=n   set brightness\n\
+  --contrast=n     set contrast\n\
+  --hue=n          set hue\n\
+  --color=n        set color\n\
+  --sharpness=n    set sharpness\n\
+  --agc=n          set agc\n\
+  --picture=n      set picture\n\
+  --explode=fname  explode a AVI file into frame.*\n\
+  -h               show usage\n\
+\n\
 ");
 
 }
@@ -81,6 +81,7 @@
 
 static char *short_options = "to:hPV:4Odvr:sjq:";
 
+#ifdef HAVE_GETOPT_LONG_H
 static struct option long_options[] = {
   {"help",        0,     0,    'h'},
   {"version",     0,     0,    OPT_VERSION},
@@ -93,6 +94,7 @@
   {"agc",         1,     0,    OPT_AGC},
   {"explode",     1,     0,    OPT_EXPLODE},
   {0, 0, 0, 0}};
+#endif
 
 int main(int argc, char *argv[])
 {
@@ -108,15 +110,20 @@
 	int snap=0;
 	int subsample=0;
 	int test=0;
+#ifdef HAVE_GETOPT_LONG_H
 	int option_index;
+#endif
 	int spic_brightness=32, spic_contrast=32, spic_hue=32, spic_color=32, spic_sharpness=32;
 	int spic_agc=48, spic_picture=0;
 	double framerate=0;
 
 	setlinebuf(stdout);
-
+#ifdef HAVE_GETOPT_LONG_H
 	while ((c = getopt_long(argc, argv, 
 				short_options, long_options, &option_index)) != -1) {
+#else
+	while ((c = getopt(argc, argv, short_options)) != -1) {
+#endif
 		switch (c) {
 		default:
 		case OPT_VERSION:
