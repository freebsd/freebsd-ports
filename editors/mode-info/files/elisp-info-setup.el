;; Setup for elisp-info.el
(require 'elisp-info)
(eval-after-load "help.el"
  (progn
    (define-key help-map "f" 'elisp-info-describe-function)
    (define-key help-map "d" 'elisp-info-describe-function)
    (define-key help-map "D" 'describe-function)
    (define-key help-map "v" 'elisp-info-describe-variable)
    (define-key help-map "V" 'describe-variable)
    (define-key help-mode-map "i" 'elisp-info-help-to-info)))
(provide 'elisp-info-setup)