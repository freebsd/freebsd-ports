--- src/calibre/library/server/content.py.orig	2016-05-20 11:45:27 UTC
+++ src/calibre/library/server/content.py
@@ -110,6 +110,7 @@ class ContentServer(object):
                      'png'  : 'image/png',
                      'gif'  : 'image/gif',
                      'html' : 'text/html',
+                     'ico'  : 'image/x-icon',
                      }[fname.rpartition('.')[-1].lower()]
         except KeyError:
             raise cherrypy.HTTPError(404, '%r not a valid resource type'%name)
