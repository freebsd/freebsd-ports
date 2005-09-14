--- config_unix.py.orig	Wed Aug 10 04:45:11 2005
+++ config_unix.py	Wed Sep 14 09:12:44 2005
@@ -4,7 +4,7 @@
 from glob import glob
 from distutils.sysconfig import get_python_inc
 
-configcommand = os.environ.get('SDL_CONFIG', 'sdl-config',)
+configcommand = os.environ.get('SDL_CONFIG', 'sdl11-config',)
 configcommand = configcommand + ' --version --cflags --libs'
 localbase = os.environ.get('LOCALBASE', '')
 
@@ -52,6 +52,9 @@
                     self.cflags += f + ' '
                 elif f[:3] == '-Wl':
                     self.cflags += '-Xlinker ' + f + ' '
+	    if self.name == 'SDL':
+		inc = '-I' + os.environ.get ('X11BASE', '') + '/include'
+		self.cflags = inc + ' ' + self.cflags
         except:
             print 'WARNING: "%s" failed!' % command    
             self.found = 0
@@ -137,7 +140,7 @@
 def main():
     print '\nHunting dependencies...'
     DEPS = [
-        DependencyProg('SDL', 'SDL_CONFIG', 'sdl-config', '1.2', 'sdl'),
+        DependencyProg('SDL', 'SDL_CONFIG', 'sdl11-config', '1.2', 'sdl'),
         Dependency('FONT', 'SDL_ttf.h', 'libSDL_ttf.so', 'SDL_ttf'),
         Dependency('IMAGE', 'SDL_image.h', 'libSDL_image.so', 'SDL_image'),
         Dependency('MIXER', 'SDL_mixer.h', 'libSDL_mixer.so', 'SDL_mixer'),
@@ -146,7 +149,7 @@
     ]
 
     if not DEPS[0].found:
-        print 'Unable to run "sdl-config". Please make sure a development version of SDL is installed.'
+        print 'Unable to run "sdl11-config". Please make sure a development version of SDL is installed.'
         raise SystemExit
 
     if localbase:
