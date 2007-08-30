---contrib/mod_ldap.c.orig	2007-07-02 15:20:31.000000000 -0800
+++ contrib/mod_ldap.c	2007-08-27 13:48:11.000000000 -0800
@@ -22,7 +22,7 @@
  */
 
 /*
- * mod_ldap v2.8.17-20070701
+ * mod_ldap v2.8.17
  *
  * Thanks for patches go to (in alphabetical order):
  *
@@ -48,7 +48,7 @@
  *                                                   LDAPDefaultAuthScheme
  *
  *
- * $Id: mod_ldap.c,v 1.54 2007/07/02 23:20:31 jwm Exp $
+ * $Id: mod_ldap.c,v 1.57 2007/08/22 02:00:06 jwm Exp $
  * $Libraries: -lldap -llber$
  */
 
@@ -70,7 +70,7 @@
 #include "conf.h"
 #include "privs.h"
 
-#define MOD_LDAP_VERSION	"mod_ldap/2.8.17-20070701"
+#define MOD_LDAP_VERSION	"mod_ldap/2.8.17"
 
 #if PROFTPD_VERSION_NUMBER < 0x0001021002
 # error MOD_LDAP_VERSION " requires ProFTPD 1.2.10rc2 or later"
@@ -2245,8 +2245,8 @@
    * ldap_init() will connect to the LDAP SDK's default.
    */
   if ((c = find_config(main_server->conf, CONF_PARAM, "LDAPServer", FALSE)) != NULL) {
-    if (strcmp(c->argv[1], "url") == 0) {
-      url = c->argv[2];
+    if (strcmp(c->argv[0], "url") == 0) {
+      url = c->argv[1];
       if (url) {
 #ifdef LDAP_OPT_X_TLS_HARD
         if (strcmp(url->lud_scheme, "ldaps") == 0) {
@@ -2269,8 +2269,8 @@
          * by other/future callers.
          */
       }
-    } else if (strcmp(c->argv[1], "host") == 0) {
-      ldap_server = c->argv[2];
+    } else if (strcmp(c->argv[0], "host") == 0) {
+      ldap_server = c->argv[1];
     } else {
       /* This should never happen, since the configuration handler for
        * LDAPServer only passes url or host, but we'll be defensive.
