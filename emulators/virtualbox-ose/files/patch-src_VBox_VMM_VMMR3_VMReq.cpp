--- src/VBox/VMM/VMMR3/VMReq.cpp.orig	2018-01-15 14:56:37 UTC
+++ src/VBox/VMM/VMMR3/VMReq.cpp
@@ -669,7 +669,7 @@ VMMR3DECL(int) VMR3ReqAlloc(PUVM pUVM, PVMREQ *ppReq, 
             Assert(pReq->enmType == VMREQTYPE_INVALID);
             Assert(pReq->enmState == VMREQSTATE_FREE);
             Assert(pReq->pUVM == pUVM);
-            ASMAtomicXchgSize(&pReq->pNext, NULL);
+            ASMAtomicXchgSize(&pReq->pNext, (uintptr_t)NULL);
             pReq->enmState = VMREQSTATE_ALLOCATED;
             pReq->iStatus  = VERR_VM_REQUEST_STATUS_STILL_PENDING;
             pReq->fFlags   = VMREQFLAGS_VBOX_STATUS;
