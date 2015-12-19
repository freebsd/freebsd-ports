--- src/calibre/library/server/content.py.orig	2015-02-20 03:34:13 UTC
+++ src/calibre/library/server/content.py
@@ -111,6 +111,7 @@ class ContentServer(object):
                      'png'  : 'image/png',
                      'gif'  : 'image/gif',
                      'html' : 'text/html',
+                     'ico'  : 'image/x-icon',
                      }[fname.rpartition('.')[-1].lower()]
         except KeyError:
             raise cherrypy.HTTPError(404, '%r not a valid resource type'%name)
