--- src/VBox/VMM/VMMR3/PDMAsyncCompletionFileNormal.cpp.orig	2025-08-13 19:52:13 UTC
+++ src/VBox/VMM/VMMR3/PDMAsyncCompletionFileNormal.cpp
@@ -37,6 +37,13 @@
 #include <iprt/string.h>
 #include <iprt/assert.h>
 #include <VBox/log.h>
+/* TBR: we need a complicated crawl through the data structure to get the AIO system limits
+   to check when considering growing the number of active AIO requests.... */
+/* We need the PDMInternal *before* the UVM, or it isn't visible afterwards. (src/VBox/VMM/include/PDMInternal.h) */
+#include <PDMInternal.h>
+#include <VBox/vmm/uvm.h>
+#include <VBox/vmm/vm.h>
+/* TBR: end of extra includes. */
 
 #include "PDMAsyncCompletionFileInternal.h"
 
@@ -1119,8 +1126,40 @@ static int pdmacFileAioMgrNormalProcessTaskList(PPDMAC
              */
             pdmacFileAioMgrNormalBalanceLoad(pAioMgr);
 #else
-            /* Grow the I/O manager */
-            pAioMgr->enmState = PDMACEPFILEMGRSTATE_GROWING;
+            /* TBR: Check the global AIO system limit before growing.
+                    This is the complicateds crawl through the data structure mentioned
+                    near the start of this file.
+                    There HAS to be a better way and better time to get this limit! */
+            PPDMASYNCCOMPLETIONEPCLASS pEpClass = NULL;
+            PCPDMASYNCCOMPLETIONEPCLASSOPS pEndpointOps = NULL;
+            PDMASYNCCOMPLETIONEPCLASSTYPE enmClassType;
+            PPDMASYNCCOMPLETIONEPCLASSFILE pEpClassFile = NULL;
+            PVM pVM = NULL;
+            PUVM pUVM = NULL;
+            unsigned int aio_system_reqests_max = RTFILEAIO_UNLIMITED_REQS;
+            pEpClass = pEndpoint->Core.pEpClass;
+            AssertMsg((NULL != pEpClass),("ep->class is NULL"));
+            pEndpointOps = pEpClass->pEndpointOps;
+            AssertMsg((NULL != pEndpointOps),("ep->class->ops is NULL"));
+            enmClassType = pEndpointOps->enmClassType;
+            AssertMsg((PDMASYNCCOMPLETIONEPCLASSTYPE_FILE == enmClassType),
+                      ("ep->class->ops->type != PDMASYNCCOMPLETIONEPCLASSTYPE_FILE"));
+            pVM = pEpClass->pVM;
+            AssertMsg((NULL != pVM),("ep->class->VM is NULL"));
+            pUVM = pVM->pUVM;
+            AssertMsg((NULL != pUVM),("ep->class->VM->UVM is NULL"));
+            pEpClassFile = (PPDMASYNCCOMPLETIONEPCLASSFILE) (pUVM->pdm.s.apAsyncCompletionEndpointClass[enmClassType]);
+            AssertMsg((NULL != pEpClassFile),("ep->class->VM->UVM->pdn[globals] is NULL"));
+            aio_system_reqests_max = pEpClassFile->cReqsOutstandingMax;
+#if 0
+            /* A one time check during development to verify getting the right number. */
+            AssertMsg((256 != aio_system_reqests_max),
+                      ("aio_system_reqests_max != 256 (val=%u)",aio_system_reqests_max));
+#endif
+            if (RT_UNLIKELY(   aio_system_reqests_max == RTFILEAIO_UNLIMITED_REQS
+                            || (pAioMgr->cRequestsActiveMax+PDMACEPFILEMGR_REQS_STEP) <= aio_system_reqests_max))
+                /* Grow the I/O manager */
+                pAioMgr->enmState = PDMACEPFILEMGRSTATE_GROWING;
 #endif
         }
     }
