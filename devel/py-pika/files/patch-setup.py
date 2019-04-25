# Fix UnicodeDecodeError: 'ascii' codec can't decode error

--- setup.py.orig	2019-04-25 11:16:05 UTC
+++ setup.py
@@ -18,7 +18,7 @@ setuptools.setup(
     name='pika',
     version='1.0.1',
     description='Pika Python AMQP Client Library',
-    long_description=open('README.rst').read(),
+    long_description=open('README.rst', 'rb').read().decode("utf-8"),
     maintainer='Gavin M. Roy',
     maintainer_email='gavinmroy@gmail.com',
     url='https://pika.readthedocs.io',
