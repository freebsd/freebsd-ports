
$FreeBSD$

--- vertex/vmahelp.c	2001/10/05 17:31:12	1.1
+++ vertex/vmahelp.c	2001/10/05 17:33:21
@@ -41,16 +41,12 @@
  */
 #define HELP_PROG_LOCATIONS	\
 { \
- "/usr/bin/gnome-help-browser", "", (char *)HELP_PROG_INPUT_TYPE_URL, \
- "/usr/local/bin/gnome-help-browser", "", (char *)HELP_PROG_INPUT_TYPE_URL, \
- "/bin/gnome-help-browser", "", (char *)HELP_PROG_INPUT_TYPE_URL, \
+ "%%X11BASE%%/bin/gnome-help-browser", "", (char *)HELP_PROG_INPUT_TYPE_URL, \
 \
- "/usr/bin/netscape", "", (char *)HELP_PROG_INPUT_TYPE_URL, \
- "/usr/local/bin/netscape", "", (char *)HELP_PROG_INPUT_TYPE_URL, \
- "/bin/netscape", "", (char *)HELP_PROG_INPUT_TYPE_URL, \
+ "%%X11BASE%%/bin/netscape", "", (char *)HELP_PROG_INPUT_TYPE_URL, \
 \
- "/usr/X11R6/bin/nxterm", "-e lynx", (char *)HELP_PROG_INPUT_TYPE_URL, \
- "/usr/X11R6/bin/xterm", "-e lynx", (char *)HELP_PROG_INPUT_TYPE_URL, \
+ "%%X11BASE%%/bin/nxterm", "-e lynx", (char *)HELP_PROG_INPUT_TYPE_URL, \
+ "%%X11BASE%%/bin/xterm", "-e lynx", (char *)HELP_PROG_INPUT_TYPE_URL, \
 \
  NULL, NULL, NULL \
 }
