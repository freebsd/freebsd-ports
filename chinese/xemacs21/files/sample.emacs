(set-language-environment 'Chinese-BIG5)
; after this, (coding-priority-list) is right,
; but describe current coding system under Mule menu 
; is wrong

(set-default-buffer-file-coding-system 'chinese-big5)
; (prefer-coding-system 'chinese-big5)
(set-input-mode nil nil t)
(setq-default default-input-method 'chinese-zozy)

(global-set-key (kbd "M-SPC") 'set-mark-command)

; even the file isn't like big5 (such as bbs article with escape)
; it would be opened in big5
; some special files would be open in different coding system
; see `file-coding-system-alist'
(setq buffer-file-coding-system-for-read 'chinese-big5)
(modify-coding-system-alist 'file "\\.jpg$" 'binary)
(modify-coding-system-alist 'file "\\.gif$" 'binary)
(modify-coding-system-alist 'file "\\.png$" 'binary)

;gnus of XEmacs doesn't have seperate group decode/encode
;it just use a universal coding-system 
;anyway.. it's good enough for most people
(modify-coding-system-alist 'network "nntp" 'chinese-big5)

;recognize all process output as chinese (like ls,man...)
;XEmacs use a lot of external programs, but if it require
;some special encoding(like binary),it would explicitly
;assign it. so don't worry.
;use big5-unix is for those situation XEmacs can't guess
;CR/LF.
(modify-coding-system-alist 'process ".*" 'big5-unix)

