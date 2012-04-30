The attached patch fixes a kernel crash on FreeBSD 10-CURRENT hosts
with VIMAGE enabled when a VM is powered off.

Submitted by:	Mikolaj Golub <trociny at freebsd.org>
--- src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c	2012-03-13 15:15:44.000000000 +0200
+++ src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c	2012-04-01 13:43:02.000000000 +0300
@@ -651,13 +651,13 @@ bool vboxNetFltOsMaybeRediscovered(PVBOX
         ng_rmnode_self(pThis->u.s.node);
         pThis->u.s.node = NULL;
     }
+    VBOXCURVNET_RESTORE();
 
     if (ifp0 != NULL)
     {
         vboxNetFltOsDeleteInstance(pThis);
         vboxNetFltOsInitInstance(pThis, NULL);
     }
-    VBOXCURVNET_RESTORE();
 
     return !ASMAtomicUoReadBool(&pThis->fDisconnectedFromHost);
 }
@@ -671,8 +671,10 @@ void vboxNetFltOsDeleteInstance(PVBOXNET
     mtx_destroy(&pThis->u.s.inq.ifq_mtx);
     mtx_destroy(&pThis->u.s.outq.ifq_mtx);
 
+    VBOXCURVNET_SET_FROM_UCRED();
     if (pThis->u.s.node != NULL)
         ng_rmnode_self(pThis->u.s.node);
+    VBOXCURVNET_RESTORE();
     pThis->u.s.node = NULL;
 }
