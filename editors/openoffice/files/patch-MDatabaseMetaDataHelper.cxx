--- ../connectivity/source/drivers/mozab/mozillasrc/MDatabaseMetaDataHelper.cxx.orig	Sat May 18 01:46:08 2002
+++ ../connectivity/source/drivers/mozab/mozillasrc/MDatabaseMetaDataHelper.cxx	Sat May 18 01:56:23 2002
@@ -2,9 +2,9 @@
  *
  *  $RCSfile: MDatabaseMetaDataHelper.cxx,v $
  *
- *  $Revision: 1.5 $
+ *  $Revision: 1.6 $
  *
- *  last change: $Author: dkenny $ $Date: 2001/12/13 09:34:19 $
+ *  last change: $Author: fs $ $Date: 2002/05/17 12:08:41 $
  *
  *  The Contents of this file are made available subject to the terms of
  *  either of the following licenses
@@ -213,11 +213,15 @@
 
 	retCode = dirFactoryService->GetDirFactory(aFactory.getStr(), getter_AddRefs(dirFactory)) ;
 	NS_ENSURE_SUCCESS (retCode, retCode) ;
-	OUString value = OStringToOUString(aFactory, RTL_TEXTENCODING_ASCII_US) ;
-	const PRUnichar *valueChars = value.getStr() ;
-	nsCOMPtr<nsISimpleEnumerator> subDirs ;
+	nsCOMPtr <nsIAbDirectoryProperties> properties;
+	properties = do_CreateInstance(NS_ABDIRECTORYPROPERTIES_CONTRACTID, &retCode);
+	NS_ENSURE_SUCCESS(retCode, retCode) ;
 
-	retCode = dirFactory->CreateDirectory(1, &kPropertyName, &valueChars, getter_AddRefs(subDirs)) ;
+	retCode = properties->SetURI(aFactory.getStr());
+	NS_ENSURE_SUCCESS(retCode,retCode);
+
+	nsCOMPtr<nsISimpleEnumerator> subDirs ;
+	retCode = dirFactory->CreateDirectory(properties, getter_AddRefs(subDirs));
 	NS_ENSURE_SUCCESS(retCode, retCode) ;
 	PRBool hasMore = PR_TRUE ;
 	nsCOMPtr<nsISupportsArray> array ;
@@ -635,12 +639,12 @@
     if ( NS_FAILED(rv) )
         return sal_False;
 
-    rv = url->SetSpec( sAbURI.getStr() );
+    rv = url->SetSpec( nsDependentCString(sAbURI.getStr()) );
     if ( NS_FAILED(rv) )
         return sal_False;
 
-    nsXPIDLCString host;
-    rv = url->GetHost(getter_Copies (host));
+    nsCAutoString host;
+    rv = url->GetAsciiHost(host);
     if ( NS_FAILED(rv) )
         return sal_False;
 
@@ -654,6 +658,11 @@
     if ( NS_FAILED(rv) )
         return sal_False;
 
+    PRUint32 options;
+    rv = url->GetOptions(&options);
+    if ( NS_FAILED(rv) )
+        return sal_False;
+
     // Get the ldap connection
     nsCOMPtr<nsILDAPConnection> ldapConnection;
     ldapConnection = do_CreateInstance(NS_LDAPCONNECTION_CONTRACTID, &rv);
@@ -671,7 +680,7 @@
 
     // Now lets initialize the LDAP connection properly. We'll kick
     // off the bind operation in the callback function, |OnLDAPInit()|.
-    rv = ldapConnection->Init(host, port, NS_ConvertASCIItoUCS2(dn).get(),
+    rv = ldapConnection->Init(host.get(), port, options, nsnull,
                               messageListener);
     if ( NS_FAILED(rv) )
         return sal_False;
