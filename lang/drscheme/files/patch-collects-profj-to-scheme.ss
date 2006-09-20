--- ../collects/profj/to-scheme.ss	2006/08/02 03:53:43	3922
+++ ../trunk/collects/profj/to-scheme.ss	2006/09/19 21:01:05	4389
@@ -341,13 +341,14 @@
         (member (id-string (name-id extend))
                 (map id-string (map def-name ordered-defs)))))
   
-  ;make-composite-name: def -> string
+  ;make-composite-name: string -> string
   (define (make-composite-name d)
-    (build-identifier (string-append (id-string (header-id (def-header d))) "-composite")))
+    (build-identifier (string-append d "-composite")))
   
   ;translate-defs: (list def) type-records -> (values (list syntax) (list reqs))
   (define (translate-defs defs type-recs)
-    (module-name (make-composite-name (car defs)))
+    (let ((sorted-d-list (sort (map (compose id-string def-name) defs) string<?)))                                   
+      (module-name (make-composite-name (car sorted-d-list))))
     (module-require (if (to-file) 
                         (let ((location (build-path (begin (send type-recs set-location! (def-file (car defs)))
                                                            (send type-recs get-compilation-location) "compiled")
