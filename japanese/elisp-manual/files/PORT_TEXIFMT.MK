;;; -*- Emacs-Lisp -*-
;;; PORT_TEXIFMT.MK --- for texinfo-format
;;; Code:

(defun port-texinfo-format (file &optional coding-system)
  (let (obuf)
    (find-file (expand-file-name file))
    (setq obuf (current-buffer))
    (require 'texinfmt)
    (texinfo-format-buffer t)
    (if coding-system
      (set-buffer-file-coding-system coding-system))
    (save-buffer)
    (kill-buffer (current-buffer))
    (kill-buffer obuf)))

;;; PORT_TEXIFMT.MK ends here
