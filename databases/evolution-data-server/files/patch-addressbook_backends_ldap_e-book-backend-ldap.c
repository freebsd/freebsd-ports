--- addressbook/backends/ldap/e-book-backend-ldap.c.orig	2007-12-14 15:23:50.000000000 +0100
+++ addressbook/backends/ldap/e-book-backend-ldap.c	2007-12-21 11:29:01.000000000 +0100
@@ -358,8 +358,8 @@
 
 	/* misc fields */
 	STRING_PROP    (E_CONTACT_HOMEPAGE_URL,  "labeledURI"),
-	/* map nickname to displayName */
-	STRING_PROP    (E_CONTACT_NICKNAME,    "displayName"),
+	/* map nickname to nickname */
+	STRING_PROP    (E_CONTACT_NICKNAME,    "nickname"),
 	E_STRING_PROP  (E_CONTACT_SPOUSE,      "spouseName"),
 	E_STRING_PROP  (E_CONTACT_NOTE,        "note"),
 	E_COMPLEX_PROP (E_CONTACT_ANNIVERSARY, "anniversary", anniversary_populate, anniversary_ber, anniversary_compare),
