--- config_unix.py.orig	Wed Aug 10 04:45:11 2005
+++ config_unix.py	Wed Sep 14 09:12:44 2005
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
