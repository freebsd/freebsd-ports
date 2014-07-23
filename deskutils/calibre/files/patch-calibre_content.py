--- src/calibre/library/server/content.py.orig	2014-07-18 13:13:33.000000000 -0500
+++ src/calibre/library/server/content.py	2014-07-18 13:14:11.000000000 -0500
@@ -111,6 +111,7 @@
                      'png'  : 'image/png',
                      'gif'  : 'image/gif',
                      'html' : 'text/html',
+                     'ico'  : 'image/x-icon',
                      }[fname.rpartition('.')[-1].lower()]
         except KeyError:
             raise cherrypy.HTTPError(404, '%r not a valid resource type'%name)
