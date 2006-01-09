--- modules/m_help.c.orig	Mon Jan  9 01:33:47 2006
+++ modules/m_help.c	Mon Jan  9 01:33:51 2006
@@ -36,8 +36,6 @@
 #include "modules.h"
 #include "irc_string.h"
 
-#define HPATH  IRCD_PREFIX "/help/opers"
-#define UHPATH IRCD_PREFIX "/help/users"
 #define HELPLEN 400
 
 static void m_help(struct Client *, struct Client *, int, char *[]);
