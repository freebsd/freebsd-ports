--- qb/config.libs.sh.orig	2025-05-01 00:17:50 UTC
+++ qb/config.libs.sh
@@ -269,8 +269,10 @@ check_val '' PULSE -lpulse '' libpulse '' '' false
 check_pkgconf ROAR libroar 1.0.12
 check_val '' JACK -ljack '' jack 0.120.1 '' false
 check_val '' PULSE -lpulse '' libpulse '' '' false
+if [ "$HAVE_PIPEWIRE" != 'no' ]; then
 check_val '' PIPEWIRE -lpipewire-0.3 '' libpipewire-0.3 '' '' false
 check_val '' PIPEWIRE_STABLE -lpipewire-0.3 '' libpipewire-0.3 1.0.0 '' false
+fi
 check_val '' SDL -lSDL SDL sdl 1.2.10 '' false
 check_val '' SDL2 -lSDL2 SDL2 sdl2 2.0.0 '' false
 
