;;
;; @(#)skk-startup.el -- skk startup elisp file.	-- shige@FreeBSD.ORG
;;

;; keybindings
(global-set-key "\C-x\C-j" 'skk-mode)
(global-set-key "\C-xt" 'skk-tutorial)

;; autoloads
(autoload 'skk-mode "skk" nil t)
(autoload 'skk-tutorial "skk-tut" nil t)
(autoload 'skk-check-jisyo "skk-tools" nil t)
(autoload 'skk-merge "skk-tools" nil t)
(autoload 'skk-diff "skk-tools" nil t)
(autoload 'skk-isearch-mode-setup "skk-isearch" nil t)
(autoload 'skk-isearch-mode-cleanup "skk-isearch" nil t)

;; addhooks
(add-hook 'isearch-mode-hook
	  (function 
	   (lambda ()
	     (and (boundp 'skk-mode) skk-mode (skk-isearch-mode-setup))
	     )))
(add-hook 'isearch-mode-end-hook
	  (function
	   (lambda ()
	     (and (boundp 'skk-mode) skk-mode
		  (skk-isearch-mode-cleanup)
		  (skk-set-cursor-color-properly))
	     )))

;; provide
(provide 'skk-startup)
