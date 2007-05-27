--- lisp/mule/cyrillic.el.orig	Sat Dec 30 19:04:32 2006
+++ lisp/mule/cyrillic.el	Fri May 25 23:03:45 2007
@@ -242,6 +242,104 @@
 
 ;;; WINDOWS-1251 deleted; we support it automatically in XEmacs
 
+;;; WINDOWS-1251 was deleted by Ben Wing.  Put back by Nickolay Pakoulin,
+;;; <npak@ispras.ru>, see comment below.
+
+;;; WINDOWS-1251
+;; On Windows platforms `windows-1251' coding system is defined in
+;; mule-win32-init.el using support for codepages provided by Microsoft
+;; libraries.  But on Unixes we have no built-in support for windows-1251, so
+;; we have define it here using ccl.
+
+;; '#-FEXP' is a special syntax for lisp reader.  Means 'ignore the next sexp
+;; when the FEXP is true'.  Here reader ignores code for windows-1251 when
+;; (featurep '(or windows-nt cygwin32)) is true.
+
+#-(or windows-nt cygwin32)
+(eval-and-compile
+
+(defvar cyrillic-windows-1251-decode-table
+  [
+   0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
+   16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
+   32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47
+   48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63
+   64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79
+   80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95
+   96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111
+   112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127
+   ?,L"(B ?,L#(B 32 ?,Ls(B 32 32 32 32 32 32 ?,L)(B 32 ?,L*(B ?,L,(B ?,L+(B ?,L/(B ;"
+   ?,Lr(B 32 32 32 32 32 32 32 32 32 ?,Ly(B 32 ?,Lz(B ?,L|(B ?,L{(B ?,L(B
+   ?,L (B ?,L.(B ?,L~(B ?,L((B ?,A$(B 32 ?,A&(B ?,L}(B ?,L!(B ?,A)(B ?,L$(B ?,A+(B ?,A,(B ?,L-(B ?,A.(B ?,L'(B
+   ?,A0(B ?,A1(B ?,L&(B ?,Lv(B 32 ?,A5(B ?,A6(B ?,A7(B ?,Lq(B ?,Lp(B ?,Lt(B ?,A;(B ?,Lx(B ?,L%(B ?,Lu(B ?,Lw(B
+  ?,L0(B ?,L1(B ?,L2(B ?,L3(B ?,L4(B ?,L5(B ?,L6(B ?,L7(B ?,L8(B ?,L9(B ?,L:(B ?,L;(B ?,L<(B ?,L=(B ?,L>(B ?,L?(B
+  ?,L@(B ?,LA(B ?,LB(B ?,LC(B ?,LD(B ?,LE(B ?,LF(B ?,LG(B ?,LH(B ?,LI(B ?,LJ(B ?,LK(B ?,LL(B ?,LM(B ?,LN(B ?,LO(B
+  ?,LP(B ?,LQ(B ?,LR(B ?,LS(B ?,LT(B ?,LU(B ?,LV(B ?,LW(B ?,LX(B ?,LY(B ?,LZ(B ?,L[(B ?,L\(B ?,L](B ?,L^(B ?,L_(B
+  ?,L`(B ?,La(B ?,Lb(B ?,Lc(B ?,Ld(B ?,Le(B ?,Lf(B ?,Lg(B ?,Lh(B ?,Li(B ?,Lj(B ?,Lk(B ?,Ll(B ?,Lm(B ?,Ln(B ?,Lo(B ]
+   "Cyrillic Windows-1251 decoding table.")
+
+(defvar cyrillic-windows-1251-encode-table
+  (let ((table (make-vector 256 32))
+	(i 0))
+    (while (< i 256)
+      (let* ((ch (aref cyrillic-windows-1251-decode-table i))
+	     (split (split-char ch)))
+	(cond ((eq (car split) 'cyrillic-iso8859-5)
+	       (aset table (logior (nth 1 split) 128) i)
+	       )
+	      ((eq ch 32))
+	      ((eq (car split) 'ascii)
+	       (aset table ch i)
+	       )))
+      (setq i (1+ i)))
+    table)
+  "Cyrillic Windows-1251 encoding table.")
+
+)
+
+#-(or windows-nt cygwin32)
+(define-ccl-program ccl-decode-windows1251
+  `(3
+    ((read r0)
+     (loop
+      (write-read-repeat r0 ,cyrillic-windows-1251-decode-table))))
+  "CCL program to decode Windows-1251.")
+
+#-(or windows-nt cygwin32)
+(define-ccl-program ccl-encode-windows1251
+  `(1
+    ((read r0)
+     (loop
+      (if (r0 != ,(charset-id 'cyrillic-iso8859-5))
+	  (write-read-repeat r0)
+	((read r0)
+	 (write-read-repeat r0 , cyrillic-windows-1251-encode-table))))))
+  "CCL program to encode Windows-1251.")
+
+#-(or windows-nt cygwin32)
+(make-coding-system
+ 'windows-1251 'ccl
+ "Coding-system used for Windows-1251."
+ '(decode ccl-decode-windows1251
+   encode ccl-encode-windows1251
+   mnemonic "CyrW"))
+
+;; `iso-8-1' is not correct, but XEmacs doesn't have a `ccl' category
+#-(or windows-nt cygwin32)
+(coding-system-put 'windows-1251 'category 'iso-8-1)
+
+#-(or windows-nt cygwin32)
+(set-language-info-alist
+ "Cyrillic-Win" '((charset cyrillic-iso8859-5)
+		   (coding-system windows-1251)
+		   (coding-priority windows-1251)
+		   (input-method . "cyrillic-yawerty")
+		   (features cyril-util)
+		   (tutorial . "TUTORIAL.ru")
+		   (sample-text . "Russian (,L@caaZXY(B)	,L7T`PRabRcYbU(B!")
+		   (documentation . "Support for Cyrillic Windows-1251."))
+ '("Cyrillic"))
+
 ;;; ALTERNATIVNYJ
 
 (eval-and-compile
