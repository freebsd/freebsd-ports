Index: emacs/pdss-init.el
===================================================================
RCS file: /ext/cvs/PDSS/emacs/pdss-init.el,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.1.2.2
diff -u -r1.1.1.1 -r1.1.1.1.2.2
--- emacs/pdss-init.el	11 Jun 2002 16:11:14 -0000	1.1.1.1
+++ emacs/pdss-init.el	1 Aug 2002 12:54:23 -0000	1.1.1.1.2.2
@@ -1,21 +1,21 @@
 ;; GNU Emacs initiation file for PDSS V2.5  (89.09.13)
 ;; Copy this file to emacs/lisp directory (see Makefile),
 ;; and insert following command into user's .emacs file.
-;;	(load "pdss-init")
+;;	(require "pdss-init")
 
 ;;-----------------------------------------------------------------------------
 ;; Path Names.
 
 (defconst pdss-directory-name
-  "/usr/local/src/pdss/"
+  "%%PREFIX%%/libexec/pdss/"
   "Directory path name of PDSS.")
 
 (defconst pdss-emacs-directory-name
-  "/usr/local/src/pdss/emacs/"
+  "%%PREFIX%%/libexec/pdss/emacs/"
   "Directory path name of PDSS.")
 
 (defconst pdss-command-name
-  (concat pdss-directory-name "emulator/pdss")
+  "pdss"
   "Command path name of PDSS emulator.")
 
 (defconst pdss-kl1cmp-compiler
@@ -39,7 +39,7 @@
   "Command path name of PDSS assembler.")
 
 (defconst pdss-manual-file-name
-  (concat pdss-directory-name "doc.j/pdss.tex")
+  "%%PREFIX%%/share/pdss/%%DOCDIR%%/pdss.tex"
   "Path name of PDSS manual file.")
 
 ;;-----------------------------------------------------------------------------
@@ -60,3 +60,5 @@
 
 (setq auto-mode-alist
       (cons '("\\.kl1$" . kl1-mode) auto-mode-alist))
+
+(provide 'pdss-init)
