--- addressbook/backends/ldap/e-book-backend-ldap.c.orig	Fri Sep  9 16:06:37 2005
+++ addressbook/backends/ldap/e-book-backend-ldap.c	Fri Sep  9 16:08:21 2005
@@ -301,8 +301,8 @@ struct prop_info {
 
 	/* misc fields */
 	STRING_PROP    (E_CONTACT_HOMEPAGE_URL,  "labeledURI"),
-	/* map nickname to displayName */
-	STRING_PROP    (E_CONTACT_NICKNAME,    "displayName"),
+	/* map nickname to nickname */
+	STRING_PROP    (E_CONTACT_NICKNAME,    "nickname"),
 	E_STRING_PROP  (E_CONTACT_SPOUSE,      "spouseName"), 
 	E_STRING_PROP  (E_CONTACT_NOTE,        "note"), 
 	E_COMPLEX_PROP (E_CONTACT_ANNIVERSARY, "anniversary", anniversary_populate, anniversary_ber, anniversary_compare), 
