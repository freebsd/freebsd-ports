--- src/wnnfns.c.orig	Mon Dec 25 19:49:21 2006
+++ src/wnnfns.c	Mon Dec 25 19:50:02 2006
@@ -341,6 +341,9 @@
 static int wnnfns_norm;
 static unsigned char lc_wnn_server_type[NSERVER] = {LCJP, LCCN, LCINV, LCKR};
 
+static int yes_or_no();
+static void puts2();
+
 /* Lisp Variables and Constants Definition */
 Lisp_Object	Qjserver;
 Lisp_Object	Qcserver;
@@ -452,8 +455,6 @@
      int			nargs;
      register Lisp_Object	*args;
 {
-  static int yes_or_no();
-  static void puts2();
   struct gcpro gcpro1;
   int	snum;
   CHECK_STRING (args[0], 0);
@@ -1293,8 +1294,6 @@
      int                        nargs;
      register Lisp_Object       *args;
 {
-  static int yes_or_no();
-  static void puts2();
   struct gcpro gcpro1;
   int   snum;
   CHECK_STRING (args[0], 0);
@@ -1329,8 +1328,6 @@
      int                        nargs;
      register Lisp_Object       *args;
 {
-  static int yes_or_no();
-  static void puts2();
   struct gcpro gcpro1;
   int   snum;
   CHECK_STRING (args[0], 0);
@@ -1365,8 +1362,6 @@
      int                        nargs;
      register Lisp_Object       *args;
 {
-  static int yes_or_no();
-  static void puts2();
   struct gcpro gcpro1;
   int   snum;
   int	dic_no;
@@ -1427,8 +1422,6 @@
      int                        nargs;
      register Lisp_Object       *args;
 {
-  static int yes_or_no();
-  static void puts2();
   struct gcpro gcpro1;
   int   snum;
   int   dic_no;
