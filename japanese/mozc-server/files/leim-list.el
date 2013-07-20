;; leim-list.el --- Mozc setup for leim API
;; $FreeBSD$$
;;
;; Copyright (c) 2013 Hiroki Sato <hrs@FreeBSD.org>.  All rights reserved.
;;
;; Redistribution and use in source and binary forms, with or without
;; modification, are permitted provided that the following conditions
;; are met:
;; 1. Redistributions of source code must retain the above copyright
;;    notice, this list of conditions and the following disclaimer.
;; 2. Redistributions in binary form must reproduce the above copyright
;;    notice, this list of conditions and the following disclaimer in the
;;   documentation and/or other materials provided with the distribution.
;;

(autoload 'mozc-mode "mozc.el" "Activate Mozc." t)
(autoload 'mozc-leim-activate "mozc.el" "Activate Mozc." t)

(defcustom mozc-leim-title "[Mozc]"
  "Mode line string shown when mozc-mode is enabled.
This indicator is not shown when you don't use LEIM."
  :type '(choice (const :tag "No indicator" nil)
                 (string :tag "Show an indicator"))
  :group 'mozc)

(register-input-method
  "japanese-mozc" "Japanese" #'mozc-leim-activate
  mozc-leim-title
  "Japanese input method with Mozc/Google Japanese Input.")
