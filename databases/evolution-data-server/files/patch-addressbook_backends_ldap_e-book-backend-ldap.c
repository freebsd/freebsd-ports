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
@@ -1698,8 +1698,9 @@
 
 	msg_type = ldap_msgtype (res);
 	if (msg_type == LDAP_RES_SEARCH_ENTRY) {
+		LDAPMessage *e;
 		g_static_rec_mutex_lock (&eds_ldap_handler_lock);
-		LDAPMessage *e = ldap_first_entry(ldap, res);
+		e = ldap_first_entry(ldap, res);
 		g_static_rec_mutex_unlock (&eds_ldap_handler_lock);
 
 		if (!e) {
@@ -1908,13 +1909,14 @@
 	   the op after either */
 	msg_type = ldap_msgtype (res);
 	if (msg_type == LDAP_RES_SEARCH_ENTRY) {
-		g_static_rec_mutex_lock (&eds_ldap_handler_lock);
-		LDAPMessage *e = ldap_first_entry (bl->priv->ldap, res);
-		g_static_rec_mutex_unlock (&eds_ldap_handler_lock);
-
 		EContact *contact;
 		char *vcard;
 
+		LDAPMessage *e;
+		g_static_rec_mutex_lock (&eds_ldap_handler_lock);
+		e = ldap_first_entry (bl->priv->ldap, res);
+		g_static_rec_mutex_unlock (&eds_ldap_handler_lock);
+
 		if (!e) {
 			g_warning ("uh, this shouldn't happen");
 			e_data_book_respond_get_contact (op->book,
@@ -3470,8 +3472,9 @@
 		g_static_rec_mutex_unlock (&eds_ldap_handler_lock);
 
 		while (NULL != e) {
+			EContact *contact;
 			g_static_rec_mutex_lock (&eds_ldap_handler_lock);
-			EContact *contact = build_contact_from_entry (ldap, e, NULL);
+			contact = build_contact_from_entry (ldap, e, NULL);
 			g_static_rec_mutex_unlock (&eds_ldap_handler_lock);
 
 			e_data_book_view_notify_update (view, contact);
@@ -3709,8 +3712,9 @@
 		g_static_rec_mutex_unlock (&eds_ldap_handler_lock);
 
 		while (e != NULL) {
+			EContact *contact;
 			g_static_rec_mutex_lock (&eds_ldap_handler_lock);
-			EContact *contact = build_contact_from_entry (ldap, e, NULL);
+			contact = build_contact_from_entry (ldap, e, NULL);
 			g_static_rec_mutex_unlock (&eds_ldap_handler_lock);
 
 			contact_list_op->contacts = g_list_prepend (contact_list_op->contacts, contact);
