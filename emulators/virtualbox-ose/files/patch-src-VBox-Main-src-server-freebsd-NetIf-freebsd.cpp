--- src/VBox/Main/src-server/freebsd/NetIf-freebsd.cpp.orig	2015-03-02 10:09:55.000000000 -0500
+++ src/VBox/Main/src-server/freebsd/NetIf-freebsd.cpp	2015-03-12 19:23:15.950051000 -0400
@@ -290,12 +290,14 @@
             ComObjPtr<HostNetworkInterface> IfObj;
             IfObj.createObject();
             if (SUCCEEDED(IfObj->init(Bstr(pNew->szName), enmType, pNew)))
+            {
                 /* Make sure the default interface gets to the beginning. */
                 if (   fDefaultIfaceExistent
                     && pIfMsg->ifm_index == u16DefaultIface)
                     list.push_front(IfObj);
                 else
                     list.push_back(IfObj);
+            }
         }
         RTMemFree(pNew);
     }
