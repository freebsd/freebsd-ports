#!/bin/sh
export LANG ; LANG=ko_KR.EUC
export XKEYSYMDB ; XKEYSYMDB=@X11BASE@/lib/X11/XKeysymDB
export XNLSPATH  ; XNLSPATH=@PREFIX@/lib/netscape/nls
export XAPPLRESDIR ; XAPPLRESDIR=@PREFIX@/lib/netscape/$LANG
export CLASSPATH ; CLASSPATH=.:@PREFIX@/lib/netscape
exec /usr/local/lib/netscape/netscape.bin $*
