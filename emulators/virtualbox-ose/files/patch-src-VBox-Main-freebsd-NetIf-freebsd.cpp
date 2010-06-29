--- src/VBox/Main/freebsd/NetIf-freebsd.cpp.orig	2010-06-07 15:34:44.000000000 +0300
+++ src/VBox/Main/freebsd/NetIf-freebsd.cpp	2010-06-18 16:45:31.000000000 +0300
@@ -180,11 +180,16 @@
     char *pBuf, *pNext;
     int aiMib[6];
     unsigned short u16DefaultIface;
+    int haveDefaultIface;
 
     /* Get the index of the interface associated with default route. */
     rc = getDefaultIfaceIndex(&u16DefaultIface, PF_INET);
-    if (RT_FAILURE(rc))
-        return rc;
+    haveDefaultIface = 1;
+    if (RT_FAILURE(rc)) {
+        Log(("NetIfList: Failed to get default route interface\n"));
+	haveDefaultIface = 0;
+	rc = VINF_SUCCESS;
+    }
 
     aiMib[0] = CTL_NET;
     aiMib[1] = PF_ROUTE;
@@ -286,7 +291,7 @@
             IfObj.createObject();
             if (SUCCEEDED(IfObj->init(Bstr(pNew->szName), enmType, pNew)))
                 /* Make sure the default interface gets to the beginning. */
-                if (pIfMsg->ifm_index == u16DefaultIface)
+                if (haveDefaultIface == 1 && pIfMsg->ifm_index == u16DefaultIface)
                     list.push_front(IfObj);
                 else
                     list.push_back(IfObj);
