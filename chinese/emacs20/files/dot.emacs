;; Set environment to Chinese-Big5
(set-language-environment 'chinese-big5)
(set-keyboard-coding-system 'chinese-big5)
(set-terminal-coding-system 'chinese-big5)
(set-buffer-file-coding-system 'chinese-big5)
(set-selection-coding-system 'chinese-big5)
(modify-coding-system-alist 'process "*" 'chinese-big5)
;; Do not conflicts with xcin hook
(global-set-key (kbd "M-SPC") 'set-mark-command)
