$FreeBSD$

--- gettext-tools/misc/po-mode.el.orig	Sun Jan 23 22:35:10 2000
+++ gettext-tools/misc/po-mode.el	Sun Jan 23 22:35:39 2000
@@ -330,7 +330,7 @@
   :type 'face
   :group 'po)
 
-(defcustom po-gzip-uuencode-command "gzip -9 | uuencode -m"
+(defcustom po-gzip-uuencode-command "gzip -9 | uuencode"
   "*The filter to use for preparing a mail invoice of the PO file.
 Normally \"gzip -9 | uuencode -m\", remove the -9 for lesser compression,
 or remove the -m if you are not using the GNU version of `uuencode'."
