--- providers/ldap/gda-ldap-provider.c.orig	Sat Jul 17 11:06:48 2004
+++ providers/ldap/gda-ldap-provider.c	Sat Jul 17 11:06:57 2004
@@ -275,7 +275,7 @@
 	switch (feature) {
 	case GDA_CONNECTION_FEATURE_SQL :
 		return TRUE;
-	default :
+	default : ;
 	}
 
 	return FALSE;
@@ -466,7 +466,7 @@
 		return get_ldap_tables (cnc, params);
 	case GDA_CONNECTION_SCHEMA_TYPES :
 		return get_ldap_types (cnc, params);
-	default :
+	default : ;
 	}
 
 	return NULL;
