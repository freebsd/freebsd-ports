--- setup.py.orig	2019-06-26 18:43:04 UTC
+++ setup.py
@@ -18,7 +18,7 @@ with open(os.path.join(os.getcwd(), 'README.txt'), 'r'
 with open(os.path.join(os.getcwd(), 'README.txt'), 'r') as _readme:
 	long_description = _readme.read()
 
-setup(name="WSGIUtils",
+setup(name="wsgiutils",
 	version= wsgiutils.__version__,
 	description="WSGI Utils are a collection of useful libraries for use in a WSGI environnment.",
 	long_description=long_description,
