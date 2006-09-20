--- ./build/platform-freebsd.mk.orig	Tue Sep 12 17:34:24 2006
+++ ./build/platform-freebsd.mk	Tue Sep 12 17:34:38 2006
@@ -45,7 +45,7 @@
 #  Meta-port "sdl_ldbad" makes symlink to sdl11-config as sdl-config.
 #  But for users who use packages only, here use sdl11-config from ports/packages "sdl12".
 #  Why "11" even "sdl12" ? We don't know. Ask to maintainer of "sdl12" ports/packages...
-SDLCONFIGSCRIPT?=$(PKGBASE)/bin/sdl11-config
+SDLCONFIGSCRIPT?=$(PKGBASE)/bin/sdl-config
 
 SDL_CFLAGS:=`$(SDLCONFIGSCRIPT) --cflags 2>> $(LOG)`
 
