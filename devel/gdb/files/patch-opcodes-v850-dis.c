--- opcodes/v850-dis.c.orig	2013-01-24 12:14:05.000000000 +0100
+++ opcodes/v850-dis.c	2013-04-29 10:10:25.000000000 +0200
@@ -73,7 +73,7 @@
   "chbwbd", "cibid", "cibiwbd", "cibwbd", "cfald", "cistd", "cildd"
 };
 
-static const int const v850_cacheop_codes[] =
+static const int v850_cacheop_codes[] =
 {
   0x00, 0x20, 0x40, 0x60, 0x61, 0x04, 0x06,
   0x07, 0x24, 0x26, 0x27, 0x44, 0x64, 0x65, -1
@@ -82,7 +82,7 @@
 static const char *const v850_prefop_names[] =
 { "prefi", "prefd" };
 
-static const int const v850_prefop_codes[] =
+static const int v850_prefop_codes[] =
 { 0x00, 0x04, -1};
 
 static void
