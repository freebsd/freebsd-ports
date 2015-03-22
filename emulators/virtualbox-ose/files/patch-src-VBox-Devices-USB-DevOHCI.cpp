--- src/VBox/Devices/USB/DevOHCI.cpp.orig	2015-03-02 10:09:35.000000000 -0500
+++ src/VBox/Devices/USB/DevOHCI.cpp	2015-03-12 16:15:51.519656000 -0400
@@ -3717,7 +3717,7 @@
             pUrb = pThis->aInFlight[i].pUrb;
             if (pThis->aInFlight[i].fInactive
                 && pUrb->enmState == VUSBURBSTATE_IN_FLIGHT
-                && !pUrb->enmType == VUSBXFERTYPE_CTRL)
+                && pUrb->enmType != VUSBXFERTYPE_CTRL)
                 pThis->RootHub.pIRhConn->pfnCancelUrbsEp(pThis->RootHub.pIRhConn, pUrb);
         }
     }
