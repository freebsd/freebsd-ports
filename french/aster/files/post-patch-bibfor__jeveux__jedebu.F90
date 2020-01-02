--- ./bibfor/jeveux/jedebu.F90.orig	2019-09-25 21:45:58.000000000 +0200
+++ ./bibfor/jeveux/jedebu.F90	2019-12-31 12:21:04.131247000 +0100
@@ -225,6 +225,7 @@
     k8tab(2) = 'VMPEAK'
     k8tab(3) = 'VMSIZE'
     call utgtme(3, k8tab, rval, iret)
+    call utmess('I', 'DEBUG_1', nr=3, valr=rval, fname='%%WRKDIR%%/aster_debug1.log')
     if (rval(2) .le. 0 .or. rval(3) .le. 0) then
         call utmess('I', 'JEVEUX1_75')
     endif
@@ -232,6 +233,7 @@
     if (rval(3) .gt. 0) then
 !
         call utptme('RLQ_MEM ', rval(3), iret)
+        call utmess('I', 'DEBUG_1', nr=3, valr=rval, fname='%%WRKDIR%%/aster_debug2.log')
         if (rval(1)-rval(3) .le. 0) then
             call utmess('F', 'JEVEUX1_71', nr=3, valr=rval)
         endif
