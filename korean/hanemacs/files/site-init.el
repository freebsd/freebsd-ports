;;; site-init.el -- site-dependent initialization file

;;
;; This init file is needed for FreeBSD ports of hanemacs
;;
;; 12 Mar 1998 CHOI Junho <junker@jazz.snu.ac.kr>
;;

; to display hangul char in X-window
(cond
 ((and
     (boundp 'emacs-major-version)
     (= emacs-major-version 19)
     (= emacs-minor-version 34))
  (standard-display-european t)
  (set-input-mode (car (current-input-mode)) (nth 1 (current-input-mode)) 0)
))

;;; site-init.el ends here
