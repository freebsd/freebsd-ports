--- src/unix/uim/scm/mozc-custom.scm.orig
+++ src/unix/uim/scm/mozc-custom.scm
@@ -137,16 +137,6 @@
          "W"
          (N_ "Word register dialog")
          (N_ "Word register dialog"))
-   (list 'action_mozc_tool_character_palette
-         'mozc_tool_character_palette
-         "P"
-         (N_ "Character palette")
-         (N_ "Character palette"))
-   (list 'action_mozc_tool_hand_writing
-         'mozc_tool_hand_writing
-         "H"
-         (N_ "Hand writing")
-         (N_ "Hand writing"))
    (list 'action_mozc_reconvert
          'mozc_reconvert
          "R"
@@ -370,27 +360,3 @@
                '(string ".*")
                (N_ "Option for word register dialog command")
                (N_ "long description will be here."))
-
-(define-custom 'mozc-tool-character-palette-cmd "/usr/lib/mozc/mozc_tool"
-               '(mozc-tool)
-               '(pathname regular-file)
-               (N_ "Path of character palette command")
-               (N_ "long description will be here."))
-
-(define-custom 'mozc-tool-character-palette-cmd-option "--mode=character_palette"
-               '(mozc-tool)
-               '(string ".*")
-               (N_ "Option for character palette command")
-               (N_ "long description will be here."))
-
-(define-custom 'mozc-tool-hand-writing-cmd "/usr/lib/mozc/mozc_tool"
-               '(mozc-tool)
-               '(pathname regular-file)
-               (N_ "Path of hand writing command")
-               (N_ "long description will be here."))
-
-(define-custom 'mozc-tool-hand-writing-cmd-option "--mode=hand_writing"
-               '(mozc-tool)
-               '(string ".*")
-               (N_ "Option for hand writing command")
-               (N_ "long description will be here."))
