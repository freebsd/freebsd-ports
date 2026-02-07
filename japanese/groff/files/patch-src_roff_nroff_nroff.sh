--- src/roff/nroff/nroff.sh~	Mon Mar 17 18:25:52 2003
+++ src/roff/nroff/nroff.sh	Mon Mar 17 18:31:52 2003
@@ -5,7 +5,7 @@
 # Default device.
 # First try the "locale charmap" command, because it's most reliable.
 # On systems where it doesn't exist, look at the environment variables.
-case "`locale charmap 2>/dev/null`" in
+case "`#locale charmap 2>/dev/null`" in
   UTF-8)
     T=-Tutf8 ;;
   ISO-8859-1)
@@ -22,7 +22,7 @@
         T=-Tlatin1 ;;
       *.IBM-1047)
         T=-Tcp1047 ;;
-      ja_JP.ujis | ja_JP.eucJP)
+      ja_JP.EUC | ja_JP.eucJP)
 	T=-Tnippon ;;
       *)
         case "$LESSCHARSET" in
