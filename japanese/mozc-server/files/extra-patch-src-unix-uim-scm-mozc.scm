--- src/unix/uim/scm/mozc.scm.orig
+++ src/unix/uim/scm/mozc.scm
@@ -98,10 +98,6 @@
        (mozc-run-process mozc-tool-dictionary-tool-cmd (list mozc-tool-dictionary-tool-cmd mozc-tool-dictionary-tool-cmd-option)))
       ((mozc-tool-word-register-dialog)
        (mozc-run-process mozc-tool-word-register-dialog-cmd (list mozc-tool-word-register-dialog-cmd mozc-tool-word-register-dialog-cmd-option)))
-      ((mozc-tool-character-palette)
-       (mozc-run-process mozc-tool-character-palette-cmd (list mozc-tool-character-palette-cmd mozc-tool-character-palette-cmd-option)))
-      ((mozc-tool-hand-writing)
-       (mozc-run-process mozc-tool-hand-writing-cmd (list mozc-tool-hand-writing-cmd mozc-tool-hand-writing-cmd-option)))
       (else
         #f))))
 
@@ -294,32 +290,6 @@
                    #f)
                  (lambda (mc)
                    (mozc-tool-activate mc 'mozc-tool-word-register-dialog)))
-
-(register-action 'action_mozc_tool_character_palette
-;;               (indication-alist-indicator 'action_mozc_tool_character_palette
-;;                                           mozc-tool-indication-alist)
-                 (lambda (mc)
-                   '(mozc_tool_character_palette
-                     "W"
-                     "Character palette"
-                     "Character palette"))
-                 (lambda (mc)
-                   #f)
-                 (lambda (mc)
-                   (mozc-tool-activate mc 'mozc-tool-character-palette)))
-
-(register-action 'action_mozc_tool_hand_writing
-;;               (indication-alist-indicator 'action_mozc_tool_hand_writing
-;;                                           mozc-tool-indication-alist)
-                 (lambda (mc)
-                   '(mozc_tool_hand_writing
-                     "W"
-                     "Hand writing"
-                     "Hand writing"))
-                 (lambda (mc)
-                   #f)
-                 (lambda (mc)
-                   (mozc-tool-activate mc 'mozc-tool-hand-writing)))
 
 (register-action 'action_mozc_reconvert
 ;;               (indication-alist-indicator 'action_mozc_reconvert
