--- src/compiler/ppc64/c-call.lisp.orig
+++ src/compiler/ppc64/c-call.lisp
@@ -25,7 +25,7 @@
 ;;;; "The stack pointer (stored in r1) shall maintain quadword alignment."
 ;;;; (quadword = 16 bytes)
 (defconstant +stack-alignment-mask+ 15)
-(defconstant +stack-frame-size+ #+little-endian 12 #+big-endian 14)
+(defconstant +stack-frame-size+ #-ppc64-elfv1 12 #+ppc64-elfv1 14)
 
 (defstruct arg-state
   (gpr-args 0)
@@ -139,7 +139,7 @@
         (arg-tns (invoke-alien-type-method :arg-tn arg-type arg-state)))
       (values (make-wired-tn* 'positive-fixnum any-reg-sc-number nsp-offset)
               (let ((size (arg-state-stack-frame-size arg-state)))
-                (cond #+little-endian
+                (cond #-ppc64-elfv1
                       ((= size +stack-frame-size+)
                        ;; no stack args
                        0)
@@ -261,7 +261,7 @@
            (make-fpr (n)
              (make-random-tn (sc-or-lose 'double-reg) n)))
       (let* ((segment (make-segment))
-             #+big-endian
+             #+ppc64-elfv1
              (function-descriptor-size 24))
         (assemble (segment 'nil)
           ;; Copy args from registers or stack to new position
@@ -387,7 +387,7 @@
                               (bug "Unknown alien floating point type: ~S" type))))))
               ;; Leave a gap for a PPC64ELF ABIv1 function descriptor,
               ;; to be filled in later relative to the SAP.
-              #+big-endian
+              #+ppc64-elfv1
               (dotimes (k (/ function-descriptor-size 4)) ; nop is 4 bytes
                 (inst nop))
               (mapc #'save-arg
@@ -411,9 +411,9 @@
               (inst stdu stack-pointer stack-pointer (- frame-size))
 
               ;; And make the call.
-              #+little-endian
+              #-ppc64-elfv1
               (load-address-into r0 (callback_wrapper_trampoline))
-              #+big-endian
+              #+ppc64-elfv1
               (destructuring-bind (r2 r12) (mapcar #'make-gpr '(2 12))
                 (load-address-into r12 (callback_wrapper_trampoline))
                 (inst ld r0 r12 0)
@@ -461,7 +461,7 @@
           ;; instruction of the wrapper.  This assembler wrapper only
           ;; cares about the address, so leave the other descriptor
           ;; fields filled with no-op instructions.
-          #+big-endian
+          #+ppc64-elfv1
           (setf (sap-ref-64 sap 0) (+ (sap-int sap) function-descriptor-size))
           (alien-funcall
            (extern-alien "ppc_flush_icache"
