Index: lisp/riece-rdcc.el
===================================================================
RCS file: /cvs/root/riece/lisp/riece-rdcc.el,v
retrieving revision 1.26
diff -u -F^( -r1.26 riece-rdcc.el
--- lisp/riece-rdcc.el	6 Jun 2004 06:11:59 -0000	1.26
+++ lisp/riece-rdcc.el	4 Nov 2004 07:12:26 -0000
@@ -64,6 +64,9 @@ (defcustom riece-rdcc-send-program
       total += bytes.length
       puts(\"#{total}\")
       session.write(bytes)
+      begin
+        buf = session.read(4)
+      end until buf.unpack('N')[0] == total
     end
   }
   session.close
@@ -198,13 +201,21 @@ (defun riece-rdcc-filter (process input)
     (let ((coding-system-for-write 'binary)
 	  jka-compr-compression-info-list jam-zcat-filename-list)
       (write-region (point-min) (point-max) riece-rdcc-temp-file t 0))
+    (setq riece-rdcc-received-size (+ (buffer-size) riece-rdcc-received-size))
+    (process-send-string
+     process
+     (format "%c%c%c%c"
+	     (logand (lsh riece-rdcc-received-size -24) 255)
+	     (logand (lsh riece-rdcc-received-size -16) 255)
+	     (logand (lsh riece-rdcc-received-size -8) 255)
+	     (logand riece-rdcc-received-size 255)))
     (message "Receiving %s from %s...(%s/%s)"
 	     (file-name-nondirectory riece-rdcc-request-file)
 	     riece-rdcc-request-user
-	     (riece-rdcc-format-size
-	      (setq riece-rdcc-received-size (+ (buffer-size)
-						riece-rdcc-received-size)))
-	     (riece-rdcc-format-size riece-rdcc-request-size))))
+	     (riece-rdcc-format-size riece-rdcc-received-size)
+	     (riece-rdcc-format-size riece-rdcc-request-size))
+    (if (= riece-rdcc-received-size riece-rdcc-request-size)
+	(set-process-filter process nil))))
 
 (defun riece-rdcc-sentinel (process status)
   (save-excursion
