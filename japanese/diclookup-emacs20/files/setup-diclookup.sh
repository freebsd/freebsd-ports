#!/bin/sh
EMACS=emacs
EMACS_VER=20.7

/usr/bin/dialog --title "ja-diclookup setup" --clear \
	--yesno "\n\
You have to install appropreate startup code for diclookup-mule. \n\
This setup script automatically it to: \n\
/usr/local/share/${EMACS}/${EMACS_VER}/site-lisp/site-start.el. \n\n\
Are you sure?" -1 -1
RETVAL=$?
# RETVAL=0 for yes, 1 for no, 255 for ESC.

if [ "X${RETVAL}" = "X0" ] ; then # answer is `Yes'. hack diclookup-mule.

# Hack /usr/local/share/${EMACS}/${EMACS_VER}/site-lisp/site-start.el
rm -f /tmp/hack-site-start.el
echo "(defun hack-site-start ()" >> /tmp/hack-site-start.el
echo "  (interactive)" >> /tmp/hack-site-start.el
echo "  (message \"Updating site-start.el.  \")" >> /tmp/hack-site-start.el
echo "  (let* ((args command-line-args-left)" >> /tmp/hack-site-start.el
echo "	 (fname (expand-file-name (nth 0 args)))" >> /tmp/hack-site-start.el
echo "	 (dir (nth 1 args)))" >> /tmp/hack-site-start.el
echo "    (setq command-line-args-left (cdr (cdr command-line-args-left)))" >> /tmp/hack-site-start.el
echo "    (set-buffer (get-buffer-create \" *x*\"))" >> /tmp/hack-site-start.el
echo "    (erase-buffer)" >> /tmp/hack-site-start.el
echo "    (if (file-exists-p fname)" >> /tmp/hack-site-start.el
echo "	(insert-file-contents fname))" >> /tmp/hack-site-start.el
echo "    (goto-char (point-min))" >> /tmp/hack-site-start.el
echo "    (if (search-forward \";;; diclookup-mule: Online dictionary\" nil t)" >> /tmp/hack-site-start.el
echo "	(message \"No changes made.\")" >> /tmp/hack-site-start.el
echo "      (goto-char (point-max))" >> /tmp/hack-site-start.el
echo "      (insert \"\n;;; diclookup-mule: Online dictionary\n\")" >> /tmp/hack-site-start.el
echo "      (insert \"(autoload 'online-dictionary \\\"diclookup-mule\\\" \")" >> /tmp/hack-site-start.el
echo "      (insert \"\\\"Online dictionary.\\\" t nil)\n\")" >> /tmp/hack-site-start.el
echo "      (insert \"(autoload 'od:lookup-pattern-edit \\\"diclookup-mule\\\" \")" >> /tmp/hack-site-start.el
echo "      (insert \"\\\"Look up a word.\\\" t nil)\n\")" >> /tmp/hack-site-start.el
echo "      (insert \"(setq od-chujiten-flag t)	; diclookup-mule\n\")" >> /tmp/hack-site-start.el
echo "      (insert \"(setq od-dictfile-list '(\\\"od-chujiten\\\" \\\"od-kojien\\\" \\\"od-readers\\\" \\\"od-crown\\\")) \")" >> /tmp/hack-site-start.el
echo "      (insert \"; diclookup-mule\n\")" >> /tmp/hack-site-start.el
echo "      (insert \"(setq dserver-server-list '(\\\"localhost\\\")) ; diclookup-mule\n\")" >> /tmp/hack-site-start.el
echo "      (insert \"(setq od-frame-geometry \\\"+0-0\\\" od-hide-frame \")" >> /tmp/hack-site-start.el
echo "      (insert \"'make-invisible) ; diclookup-mule\n\")" >> /tmp/hack-site-start.el
echo "      (insert \"(add-hook 'od-really-quit-hook 'od-delete-frame) \")" >> /tmp/hack-site-start.el
echo "      (insert \"; diclookup-mule\n\")" >> /tmp/hack-site-start.el
echo "      (insert \"(define-key-after menu-bar-file-menu [dictionary] \")" >> /tmp/hack-site-start.el
echo "      (insert \"; diclookup-mule\n\")" >> /tmp/hack-site-start.el
echo "      (insert \"	'(\\\"Online Dictionary\\\" . online-dictionary) 'calendar) \")" >> /tmp/hack-site-start.el
echo "      (insert \"; diclookup-mule\n\")" >> /tmp/hack-site-start.el
echo "      (write-file fname))))" >> /tmp/hack-site-start.el

${EMACS}-${EMACS_VER} -batch -q -l /tmp/hack-site-start.el -f hack-site-start \
		/usr/local/share/${EMACS}/${EMACS_VER}/site-lisp/site-start.el ;
rm -f /tmp/hack-site-start.el

/usr/bin/dialog --title "ja-diclookup setup" --clear \
	--msgbox "\n\
original file is saved in /usr/local/share/${EMACS}/${EMACS_VER}/site-lisp/site-start.el.bak" -1 -1

else
/usr/bin/dialog --title "ja-diclookup setup" --clear \
	--msgbox "\n\
For setup, documents under /usr/local/share/doc/diclookup-emacs20 
will be helpful." -1 -1
fi
