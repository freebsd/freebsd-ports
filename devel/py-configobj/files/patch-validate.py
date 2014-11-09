--- validate.py.orig	2010-03-01 23:04:02 UTC
+++ validate.py
@@ -284,7 +284,7 @@
     except socket.error:
         # bug in inet_aton, corrected in Python 2.4
         if ip.strip() == '255.255.255.255':
-            return 0xFFFFFFFFL
+            return 0xFFFFFFFF
         else:
             raise ValueError('Not a good dotted-quad IP: %s' % ip)
     return
@@ -316,7 +316,7 @@
     import socket, struct
     
     # no need to intercept here, 4294967295L is fine
-    if num > 4294967295L or num < 0:
+    if num > 4294967295 or num < 0:
         raise ValueError('Not a good numeric IP: %s' % num)
     try:
         return socket.inet_ntoa(
@@ -739,7 +739,7 @@
         elif isinstance(val, (int, long, float, basestring)):
             try:
                 out_params.append(fun(val))
-            except ValueError, e:
+            except ValueError as e:
                 raise VdtParamError(name, val)
         else:
             raise VdtParamError(name, val)
@@ -1292,7 +1292,7 @@
         raise VdtValueTooLongError(value)
     try:
         return [fun_dict[arg](val) for arg, val in zip(args, value)]
-    except KeyError, e:
+    except KeyError as e:
         raise VdtParamError('mixed_list', e)
 
 
