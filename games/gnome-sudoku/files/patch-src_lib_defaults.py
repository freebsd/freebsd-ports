python locale uses C library gettext modules. Since our gettext doesn't
live in libc, work around this.

--- src/lib/defaults.py.orig	2014-06-29 20:25:20.000000000 +0000
+++ src/lib/defaults.py	2014-06-30 08:36:06.856480939 +0000
@@ -39,7 +39,7 @@
     PUZZLE_DIR      = BASE_DIR
 
 DOMAIN = 'gnome-sudoku'
-locale.bind_textdomain_codeset(DOMAIN, "UTF-8") # See Bug 608425
+gettext.bind_textdomain_codeset(DOMAIN, "UTF-8") # See Bug 608425
 gettext.bindtextdomain(DOMAIN, LOCALEDIR)
 gettext.textdomain(DOMAIN)
 from gettext import gettext as _
