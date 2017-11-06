This diff is a slightly modified version of the one from
http://lists.gnu.org/archive/html/emacs-devel/2015-02/msg00274.html

It traces its origin back to https://gitorious.org/lldb/lldb/commit/40e4dbf

It's also present on Apple's OS site:

http://www.opensource.apple.com/source/lldb/lldb-76/utils/emacs/

--- lisp/progmodes/gud.el.orig	2017-03-23 15:07:51 UTC
+++ lisp/progmodes/gud.el
@@ -35,7 +35,7 @@
 ;; kluge with the gud-xdb-directories hack producing gud-dbx-directories.
 ;; Derek L. Davies <ddavies@world.std.com> added support for jdb (Java
 ;; debugger.)  Jan Nieuwenhuizen added support for the Guile REPL (Guile
-;; debugger).
+;; debugger). llvm.org added support for lldb.
 
 ;;; Code:
 
@@ -56,7 +56,7 @@
 
 (defgroup gud nil
   "The \"Grand Unified Debugger\" interface.
-Supported debuggers include gdb, sdb, dbx, xdb, perldb,
+Supported debuggers include lldb, gdb, sdb, dbx, xdb, perldb,
 pdb (Python), and jdb."
   :group 'processes
   :group 'tools)
@@ -141,12 +141,12 @@ Used to gray out relevant toolbar icons.
 			       (display-graphic-p)
 			       (fboundp 'x-show-tip))
 		  :visible (memq gud-minor-mode
-				'(gdbmi guiler dbx sdb xdb pdb))
+				'(lldb gdbmi guiler dbx sdb xdb pdb))
 	          :button (:toggle . gud-tooltip-mode))
     ([refresh]	"Refresh" . gud-refresh)
     ([run]	menu-item "Run" gud-run
                   :enable (not gud-running)
-		  :visible (or (memq gud-minor-mode '(gdb dbx jdb))
+		  :visible (or (memq gud-minor-mode '(lldb gdb dbx jdb))
 			       (and (eq gud-minor-mode 'gdbmi)
 				    (or (not (gdb-show-run-p))
 					(bound-and-true-p
@@ -168,18 +168,18 @@ Used to gray out relevant toolbar icons.
     ([tbreak]	menu-item "Temporary Breakpoint" gud-tbreak
                   :enable (not gud-running)
 		  :visible (memq gud-minor-mode
-				'(gdbmi gdb sdb xdb)))
+				'(lldb gdbmi gdb sdb xdb)))
     ([break]	menu-item "Set Breakpoint" gud-break
                   :enable (not gud-running)
 		  :visible (gud-tool-bar-item-visible-no-fringe))
     ([up]	menu-item "Up Stack" gud-up
 		  :enable (not gud-running)
 		  :visible (memq gud-minor-mode
-				 '(gdbmi gdb guiler dbx xdb jdb pdb)))
+				 '(lldb gdbmi gdb guiler dbx xdb jdb pdb)))
     ([down]	menu-item "Down Stack" gud-down
 		  :enable (not gud-running)
 		  :visible (memq gud-minor-mode
-				 '(gdbmi gdb guiler dbx xdb jdb pdb)))
+				 '(lldb gdbmi gdb guiler dbx xdb jdb pdb)))
     ([pp]	menu-item "Print S-expression" gud-pp
                   :enable (and (not gud-running)
 				  (bound-and-true-p gdb-active-process))
@@ -191,7 +191,7 @@ Used to gray out relevant toolbar icons.
 			      "Dump object"
 			    "Print Dereference") gud-pstar
                   :enable (not gud-running)
-		  :visible (memq gud-minor-mode '(gdbmi gdb jdb)))
+		  :visible (memq gud-minor-mode '(lldb gdbmi gdb jdb)))
     ([print]	menu-item "Print Expression" gud-print
                   :enable (not gud-running))
     ([watch]	menu-item "Watch Expression" gud-watch
@@ -200,13 +200,13 @@ Used to gray out relevant toolbar icons.
     ([finish]	menu-item "Finish Function" gud-finish
                   :enable (not gud-running)
 		  :visible (memq gud-minor-mode
-				 '(gdbmi gdb guiler xdb jdb pdb)))
+				 '(lldb gdbmi gdb guiler xdb jdb pdb)))
     ([stepi]	menu-item "Step Instruction" gud-stepi
                   :enable (not gud-running)
-		  :visible (memq gud-minor-mode '(gdbmi gdb dbx)))
+		  :visible (memq gud-minor-mode '(lldb gdbmi gdb dbx)))
     ([nexti]	menu-item "Next Instruction" gud-nexti
                   :enable (not gud-running)
-		  :visible (memq gud-minor-mode '(gdbmi gdb dbx)))
+		  :visible (memq gud-minor-mode '(lldb gdbmi gdb dbx)))
     ([step]	menu-item "Step Line" gud-step
                   :enable (not gud-running))
     ([next]	menu-item "Next Line" gud-next
@@ -241,7 +241,7 @@ Used to gray out relevant toolbar icons.
 	:visible (not (eq gud-minor-mode 'gdbmi)))
        ([menu-bar run] menu-item
 	,(propertize "run" 'face 'font-lock-doc-face) gud-run
-	:visible (memq gud-minor-mode '(gdbmi gdb dbx jdb)))
+	:visible (memq gud-minor-mode '(lldb gdbmi gdb dbx jdb)))
        ([menu-bar go] menu-item
 	,(propertize " go " 'face 'font-lock-doc-face) gud-go
 	:visible (and (eq gud-minor-mode 'gdbmi)
@@ -360,6 +360,7 @@ are interpreted specially if present.  T
   %l -- Number of current source line.
   %e -- Text of the C lvalue or function-call expression surrounding point.
   %a -- Text of the hexadecimal address surrounding point.
+  %b -- Text of the most recently created breakpoint id.
   %p -- Prefix argument to the command (if any) as a number.
   %c -- Fully qualified class name derived from the expression
         surrounding point (jdb only).
@@ -974,6 +975,131 @@ SKIP is the number of chars to skip on e
 
 
 ;; ======================================================================
+;; lldb functions
+
+;; History of argument lists passed to lldb.
+(defvar gud-lldb-history nil)
+
+;; Keeps track of breakpoint created.  In the following case, the id is "1".
+;; It is used to implement temporary breakpoint.
+;; (lldb) b main.c:39
+;; breakpoint set --file 'main.c' --line 39
+;; Breakpoint created: 1: file ='main.c', line = 39, locations = 1
+(defvar gud-breakpoint-id nil)
+
+(defun lldb-extract-breakpoint-id (string)
+  ;; Search for "Breakpoint created: \\([^:\n]*\\):" pattern.
+  (if (string-match "Breakpoint created: \\([^:\n]*\\):" string)
+      (progn
+        (setq gud-breakpoint-id (match-string 1 string))
+        (message "breakpoint id: %s" gud-breakpoint-id)))
+)
+
+(defun gud-lldb-marker-filter (string)
+  (setq gud-marker-acc
+	(if gud-marker-acc (concat gud-marker-acc string) string))
+  (lldb-extract-breakpoint-id gud-marker-acc)
+  (let (start)
+    ;; Process all complete markers in this chunk
+    (while (or
+            ;; (lldb) r
+            ;; Process 15408 launched: '/Volumes/data/lldb/svn/trunk/test/conditional_break/a.out' (x86_64)
+            ;; (lldb) Process 15408 stopped
+            ;; * thread #1: tid = 0x2e03, 0x0000000100000de8 a.out`c + 7 at main.c:39, stop reason = breakpoint 1.1, queue = com.apple.main-thread
+            (string-match " at \\([^:\n]*\\):\\([0-9]*\\), stop reason = .*\n"
+                          gud-marker-acc start)
+            ;; (lldb) frame select -r 1
+            ;; frame #1: 0x0000000100000e09 a.out`main + 25 at main.c:44
+            (string-match "\nframe.* at \\([^:\n]*\\):\\([0-9]*\\)\n"
+                           gud-marker-acc start))
+      (setq gud-last-frame
+            (cons (match-string 1 gud-marker-acc)
+                  (string-to-number (match-string 2 gud-marker-acc)))
+            start (match-end 0)))
+
+    ;; Search for the last incomplete line in this chunk
+    (while (string-match "\n" gud-marker-acc start)
+      (setq start (match-end 0)))
+
+    ;; If we have an incomplete line, store it in gud-marker-acc.
+    (setq gud-marker-acc (substring gud-marker-acc (or start 0))))
+  string)
+
+;; Keeps track of whether the Python lldb_oneshot_break function definition has
+;; been exec'ed.
+(defvar lldb-oneshot-break-defined nil)
+
+;;;###autoload
+(defun lldb (command-line)
+  "Run lldb on program FILE in buffer *gud-FILE*.
+The directory containing FILE becomes the initial working directory
+and source-file directory for your debugger."
+  (interactive (list (gud-query-cmdline 'lldb)))
+
+  (gud-common-init command-line nil 'gud-lldb-marker-filter)
+  (set (make-local-variable 'gud-minor-mode) 'lldb)
+  (setq lldb-oneshot-break-defined nil)
+
+  (gud-def gud-listb  "breakpoint list"
+                      "l"    "List all breakpoints.")
+  (gud-def gud-bt     "thread backtrace"
+                      "b"    "Show stack for the current thread.")
+  (gud-def gud-bt-all "thread backtrace all"
+                      "B"    "Show stacks for all the threads.")
+
+  (gud-def gud-break  "breakpoint set -f %f -l %l"
+                      "\C-b" "Set breakpoint at current line.")
+  (gud-def gud-tbreak
+	   (progn (gud-call "breakpoint set -f %f -l %l")
+                  (sit-for 1)
+                  (if (not lldb-oneshot-break-defined)
+                      (progn
+                        ;; The "\\n"'s are required to escape the newline chars
+                        ;; passed to the lldb process.
+                        (gud-call (concat "script exec \"def lldb_oneshot_break(frame, bp_loc):\\n"
+                                                        "    target=frame.GetThread().GetProcess().GetTarget()\\n"
+                                                        "    bp=bp_loc.GetBreakpoint()\\n"
+                                                        "    print 'Deleting oneshot breakpoint:', bp\\n"
+                                                        "    target.BreakpointDelete(bp.GetID())\""))
+                        (sit-for 1)
+                        ;; Set the flag since Python knows about the function def now.
+                        (setq lldb-oneshot-break-defined t)))
+                  (gud-call "breakpoint command add -p %b -o 'lldb_oneshot_break(frame, bp_loc)'"))
+	              "\C-t" "Set temporary breakpoint at current line.")
+  (gud-def gud-remove "breakpoint clear -f %f -l %l"
+                      "\C-d" "Remove breakpoint at current line")
+  (gud-def gud-step   "thread step-in"
+                      "\C-s" "Step one source line with display.")
+  (gud-def gud-stepi  "thread step-inst"
+                      "\C-i" "Step one instruction with display.")
+  (gud-def gud-next   "thread step-over"
+                      "\C-n" "Step one line (skip functions).")
+  (gud-def gud-nexti  "thread step-inst-over"
+                      nil    "Step one instruction (skip functions).")
+  (gud-def gud-cont   "process continue"
+                      "\C-r" "Continue with display.")
+  (gud-def gud-finish "thread step-out"
+                      "\C-f" "Finish executing current function.")
+  (gud-def gud-up     "frame select -r %p"
+                      "<"    "Up 1 stack frame.")
+  (gud-def gud-down   "frame select -r -%p"
+                      ">"    "Down 1 stack frame.")
+  (gud-def gud-print  "expression -- %e"
+                      "\C-p" "Evaluate C expression at point.")
+  (gud-def gud-pstar  "expression -- *%e"
+                      nil    "Evaluate C dereferenced pointer expression at point.")
+  (gud-def gud-run    "run"
+                      nil    "Run the program.")
+  (gud-def gud-stop-subjob    "process kill"
+                      nil    "Stop the program.")
+
+  (setq comint-prompt-regexp  "\\(^\\|\n\\)\\*")
+  (setq paragraph-start comint-prompt-regexp)
+  (run-hooks 'lldb-mode-hook)
+  )
+
+
+;; ======================================================================
 ;; sdb functions
 
 ;; History of argument lists passed to sdb.
@@ -2504,9 +2630,10 @@ gud, see `gud-mode'."
   "Major mode for interacting with an inferior debugger process.
 
    You start it up with one of the commands M-x gdb, M-x sdb, M-x dbx,
-M-x perldb, M-x xdb, or M-x jdb.  Each entry point finishes by executing a
-hook; `gdb-mode-hook', `sdb-mode-hook', `dbx-mode-hook',
-`perldb-mode-hook', `xdb-mode-hook', or `jdb-mode-hook' respectively.
+M-x perldb, M-x xdb, M-x jdb, or M-x lldb.  Each entry point finishes by
+executing a hook; `gdb-mode-hook', `sdb-mode-hook', `dbx-mode-hook',
+`perldb-mode-hook', `xdb-mode-hook', `jdb-mode-hook', or `lldb-mode-hook'
+respectively.
 
 After startup, the following commands are available in both the GUD
 interaction buffer and any source buffer GUD visits due to a breakpoint stop
@@ -2536,7 +2663,7 @@ Under gdb, sdb and xdb, \\[gud-tbreak] b
 except that the breakpoint is temporary; that is, it is removed when
 execution stops on it.
 
-Under gdb, dbx, and xdb, \\[gud-up] pops up through an enclosing stack
+Under gdb, dbx, xdb, and lldb, \\[gud-up] pops up through an enclosing stack
 frame.  \\[gud-down] drops back down through one.
 
 If you are using gdb or xdb, \\[gud-finish] runs execution to the return from
@@ -2858,7 +2985,7 @@ Obeying it means displaying in another w
 	result)
     (while (and str
 		(let ((case-fold-search nil))
-		  (string-match "\\([^%]*\\)%\\([adefFlpc]\\)" str)))
+		  (string-match "\\([^%]*\\)%\\([abdefFlpc]\\)" str)))
       (let ((key (string-to-char (match-string 2 str)))
 	    subst)
 	(cond
@@ -2886,6 +3013,8 @@ Obeying it means displaying in another w
 	  (setq subst (gud-find-expr)))
 	 ((eq key ?a)
 	  (setq subst (gud-read-address)))
+	 ((eq key ?b)
+	  (setq subst gud-breakpoint-id))
 	 ((eq key ?c)
 	  (setq subst
                 (gud-find-class
@@ -3521,6 +3650,7 @@ With arg, dereference expr if ARG is pos
 (defun gud-tooltip-print-command (expr)
   "Return a suitable command to print the expression EXPR."
   (pcase gud-minor-mode
+    (`lldb (concat "expression -o -- \"" expr "\""))
     (`gdbmi (concat "-data-evaluate-expression \"" expr "\""))
     (`guiler expr)
     (`dbx (concat "print " expr))
