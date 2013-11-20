python locale uses C library gettext modules. Since our gettext doesn't
live in libc, work around this.

--- src/lib/defaults.py.orig	2013-08-24 19:50:08.000000000 +0200
+++ src/lib/defaults.py	2013-08-24 20:02:02.000000000 +0200
@@ -39,7 +39,7 @@
     PUZZLE_DIR      = BASE_DIR
 
 DOMAIN = 'gnome-games'
-locale.bind_textdomain_codeset(DOMAIN, "UTF-8") # See Bug 608425
+gettext.bind_textdomain_codeset(DOMAIN, "UTF-8") # See Bug 608425
 gettext.bindtextdomain(DOMAIN, LOCALEDIR)
 gettext.textdomain(DOMAIN)
 from gettext import gettext as _
