#!/bin/sh
export XKEYSYMDB ; XKEYSYMDB=@X11BASE@/lib/X11/XKeysymDB
export XNLSPATH  ; XNLSPATH=@X11BASE@/lib/X11/nls
export XAPPLRESDIR ; XAPPLRESDIR=@X11BASE@/lib/X11/ko_KR.EUC/app-defaults
export CLASSPATH ; CLASSPATH=.:/usr/local/lib/netscape
export LANG; LANG=ko_KR.EUC
exec /usr/local/lib/netscape/netscape.bin $*
