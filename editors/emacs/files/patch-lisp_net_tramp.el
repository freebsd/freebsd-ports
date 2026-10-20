--- lisp/net/tramp.el.orig	2026-08-24 08:33:21 UTC
+++ lisp/net/tramp.el
@@ -1071,7 +1071,7 @@ Derived from `tramp-postfix-method-format'.")
 Derived from `tramp-postfix-method-format'.")
 
 (defconst tramp-user-regexp
-  (rx (| (+ (not (any "/\\^$?*:;|[]{}()<>`'\"" blank)))
+  (rx (| (+ (not (any "/\\^$!#&?*:;,|[]{}()<>`'\"" blank control)))
 	 ;; Environment variable.
 	 (: "$" (+ (any "_" alnum)))))
   "Regexp matching user names.")
@@ -1826,6 +1826,11 @@ This is HOST, if non-nil.  Otherwise, do a lookup in
 	result
       (propertize result 'tramp-default t))))
 
+(defvar tramp-allow-double-percent (not (eq system-type 'windows-nt))
+  "Whether a pattern \"%NAME%\" can be used in user or host names.
+It is not recommended to change this variable globally.  Instead, it
+should be set connection-local.")
+
 ;;;###tramp-autoload
 (defun tramp-dissect-file-name (name &optional nodefault)
   "Return a `tramp-file-name' structure of NAME, a remote file name.
@@ -1892,7 +1897,37 @@ default values are used."
 	  ;; Only some methods from tramp-sh.el do support multi-hops.
 	  (unless (or (null hop) nodefault non-essential (tramp-multi-hop-p v))
 	    (tramp-user-error
-	     v "Method `%s' is not supported for multi-hops" method)))))))
+	     v "Method `%s' is not supported for multi-hops" method))
+	  (let (connection-local-variables-alist)
+	    (hack-connection-local-variables
+	     (tramp-get-connection-local-criteria v))
+	    (let ((allow-double-percent
+		   (alist-get
+		    'tramp-allow-double-percent
+		    connection-local-variables-alist
+		    tramp-allow-double-percent)))
+	      ;; User name could be invalid after expansion of
+	      ;; environment variables, or contain a literal
+	      ;; environment variable.
+	      (unless (tramp-string-empty-or-nil-p user)
+		(when (or (not (string-match-p tramp-user-regexp user))
+			  (string-match-p
+			   (rx "$") (tramp-file-name-user-domain v))
+			  (and (not allow-double-percent)
+			       (string-match-p
+				(rx "%" (* nonl) "%")
+				(tramp-file-name-user-domain v))))
+		  (tramp-user-error
+		   v "Not a valid user name: \"%s\""
+		   (tramp-file-name-user-domain v))))
+	      ;; Host name could contain a literal environment variable.
+	      (unless (tramp-string-empty-or-nil-p host)
+		(when (or (not (string-match-p tramp-host-regexp host))
+			  (string-match-p (rx "$") host)
+			  (and (not allow-double-percent)
+			       (string-match-p (rx "%" (* nonl) "%") host)))
+		  (tramp-user-error
+		   v "Not a valid host name: \"%s\"" host))))))))))
 
 ;; We cannot use the `declare' form for `tramp-suppress-trace' in
 ;; autoloaded functions, because the tramp-loaddefs.el generation
