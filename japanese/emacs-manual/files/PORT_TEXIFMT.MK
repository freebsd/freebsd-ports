;;; -*- Emacs-Lisp -*-
;;; PORT_TEXIFMT.MK --- for texinfo-format
;;; Code:

(defun port-texinfo-format ()
  (let (obuf)
    (find-file (expand-file-name PORT-TEXI))
    (setq obuf (current-buffer))
    (require 'texinfmt)
    (texinfo-format-buffer t)
    (set-buffer-file-coding-system 'iso-2022-jp)
    (save-buffer)
    (kill-buffer (current-buffer))
    (kill-buffer obuf)))

;;; PORT_TEXIFMT.MK ends here
