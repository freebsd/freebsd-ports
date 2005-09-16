--- contrib/m_help.c.orig	Sat Jul 23 15:52:17 2005
+++ contrib/m_help.c	Sat Jul 23 15:50:40 2005
@@ -36,8 +36,6 @@
 #include "modules.h"
 #include "irc_string.h"
 
-#define HPATH  IRCD_PREFIX "/help/opers"
-#define UHPATH IRCD_PREFIX "/help/users"
 #define HELPLEN 400
 
 static void m_help(struct Client*, struct Client*, int, char *[]);
