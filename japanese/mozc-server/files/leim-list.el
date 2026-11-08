;; leim-list.el --- Mozc setup for leim API -*- lexical-binding: nil; -*-
;;
;; Copyright (c) 2013, 2026 Hiroki Sato <hrs@FreeBSD.org>
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
;; THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
;; ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
;; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
;; ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
;; FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
;; DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
;; OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
;; HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
;; LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
;; OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
;; SUCH DAMAGE.

(autoload 'mozc-mode "mozc" "Activate Mozc." t)
(defun mozc-leim-activate (input-method)
  "Activate Mozc through its own LEIM registration."
  (require 'mozc)
  (mozc-leim-register-input-method)
  (funcall (nth 2 (assoc input-method input-method-alist))
           input-method))

(defcustom mozc-leim-title "[Mozc]"
  "Mode line string shown when mozc-mode is enabled.
This indicator is not shown when you don't use LEIM."
  :type '(choice (const :tag "No indicator" nil)
                 (string :tag "Show an indicator"))
  :group 'mozc)

(register-input-method
  "japanese-mozc" "Japanese" #'mozc-leim-activate
  mozc-leim-title
  "Japanese input method with Mozc.")
