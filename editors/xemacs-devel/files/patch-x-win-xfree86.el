Index: lisp/x-win-xfree86.el
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/lisp/x-win-xfree86.el,v
retrieving revision 1.5
retrieving revision 1.6
diff -u -r1.5 -r1.6
--- lisp/x-win-xfree86.el	2001/05/04 22:42:19	1.5
+++ lisp/x-win-xfree86.el	2005/12/24 19:53:53	1.6
@@ -46,6 +46,37 @@
 
 ;;;###autoload
 (defun x-win-init-xfree86 ()
+
+  ;; We know this keyboard is an XFree86 keyboard. As such, we can predict
+  ;; what key scan codes will correspond to the keys on US keyboard layout,
+  ;; and we can use that information to fall back to the US layout when
+  ;; looking up commands that would otherwise fail. (Cf. the hard-coding of
+  ;; this information in /usr/X11R6/lib/X11/xkb/keycodes/xfree86 )
+  ;;
+  ;; These settings for x-us-keymap-first-keycode and
+  ;; x-us-keymap-description were determined with 
+  ;; 
+  ;; setxkbmap us
+  ;; xmodmap -pke > keyboard-description.txt
+  ;;
+  ;; "8" is the key code of the first line, x-us-keymap-description is
+  ;; taken from the column describing the bindings. 
+
+  (setq x-us-keymap-first-keycode 8
+	x-us-keymap-description
+	[nil nil [?1 ?!] [?2 ?@] [?3 ?\#] [?4 ?$] [?5 ?%] [?6 ?^] [?7 ?&]
+	     [?8 ?*] [?9 ?\(] [?0 ?\)] [?- ?_] [?= ?+] nil ?\t [?q ?Q] 
+	     [?w ?W] [?e ?E] [?r ?R] [?t ?T] [?y ?Y] [?u ?U] [?i ?I] [?o ?O]
+	     [?p ?P] [?\[ ?{] [?\] ?}] nil nil [?a ?A] [?s ?S] [?d ?D]
+	     [?f ?F] [?g ?G] [?h ?H] [?j ?J] [?k ?K] [?l ?L] [?\; ?:]
+	     [?\' ?\"] [?\` ?~] nil [?\\ ?|] [?z ?Z] [?x ?X] [?c ?C]
+	     [?v ?V] [?b ?B] [?n ?N] [?m ?M] [?\, ?<] [?\. ?>] [?/ ?\?]
+	     nil ?* nil ?\  nil nil nil nil nil nil nil nil nil nil nil
+	     nil nil ?7 ?8 ?9 ?- ?4 ?5 ?6 ?+ ?1 ?2 ?3 ?0 ?\. nil nil 
+	     [?< ?>] nil nil nil nil nil nil nil nil nil nil nil nil 
+	     nil nil nil nil nil ?/ nil nil nil nil nil nil nil nil 
+	     nil nil nil nil nil ?=])
+
   (loop for (key sane-key) in
     '((f13 f1)
       (f14 f2)
