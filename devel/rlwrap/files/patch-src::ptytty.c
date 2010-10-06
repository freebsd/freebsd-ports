--- src/ptytty.c.orig	2010-01-24 01:05:53.000000000 -0800
+++ src/ptytty.c	2010-01-24 01:09:19.000000000 -0800
@@ -159,11 +159,19 @@
     char pty_name[] = "/dev/pty??";
     char tty_name[] = "/dev/tty??";
 
-# ifndef PTYCHAR1
-#  define PTYCHAR1      "pqrstuvwxyz"
-# endif
-# ifndef PTYCHAR2
-#  define PTYCHAR2      "0123456789abcdef"
+# ifdef __FreeBSD__
+/* Auto-detected pty names do not work well with devfs! */
+#  undef  PTYCHAR1
+#  define PTYCHAR1	"pqrsPQRS"
+#  undef  PTYCHAR2
+#  define PTYCHAR2	"0123456789abcdefghijklmnopqrstuv"
+# else
+#  ifndef PTYCHAR1
+#   define PTYCHAR1	"pqrstuvwxyz"
+#  endif
+#  ifndef PTYCHAR2
+#   define PTYCHAR2	"0123456789abcdef"
+#  endif
 # endif
     for (c1 = PTYCHAR1; *c1; c1++) {
       pty_name[(sizeof(pty_name) - 3)] =
