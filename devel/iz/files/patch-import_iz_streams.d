--- import/iz/streams.d	2017-04-03 03:39:24 UTC
+++ import/iz/streams.d
@@ -1049,7 +1049,12 @@ abstract class SystemStream: Stream, Str
             }
             version(Posix)
             {
-                return core.sys.posix.unistd.lseek64(_handle, offset, mode);
+                version(FreeBSD)
+                {
+                	return core.sys.posix.unistd.lseek(_handle, offset, mode);
+		} else {
+                	return core.sys.posix.unistd.lseek64(_handle, offset, mode);
+		}
             }
         }
 
@@ -1085,7 +1090,12 @@ abstract class SystemStream: Stream, Str
             }
             version(Posix)
             {
-                ftruncate64(_handle, value);
+		version(FreeBSD)
+		{
+	                ftruncate(_handle, value);
+		} else {
+	                ftruncate64(_handle, value);
+		}
             }
         }
 
@@ -1574,7 +1584,12 @@ class MemoryStream: Stream, StreamPersis
 
                 scope(exit) core.sys.posix.unistd.close(hdl);
                 auto immutable numRead = core.sys.posix.unistd.write(hdl, _memory, _size);
-                ftruncate64(hdl, _size);
+                version(FreeBSD)
+                {
+	                ftruncate(hdl, _size);
+		} else {
+	                ftruncate64(hdl, _size);
+		}
 
                 if (numRead != _size)
                     throw new Exception(format("stream exception: '%s' is corrupted", aFilename));
@@ -1611,8 +1626,14 @@ class MemoryStream: Stream, StreamPersis
                     throw new Exception(format("stream exception: cannot open '%s'", aFilename));
 
                 scope(exit) core.sys.posix.unistd.close(hdl);
-                size(core.sys.posix.unistd.lseek64(hdl, 0, SEEK_END));
-                core.sys.posix.unistd.lseek64(hdl, 0, SEEK_SET);
+                version(FreeBSD)
+                {
+	                size(core.sys.posix.unistd.lseek(hdl, 0, SEEK_END));
+        	        core.sys.posix.unistd.lseek(hdl, 0, SEEK_SET);
+		} else {
+                	size(core.sys.posix.unistd.lseek64(hdl, 0, SEEK_END));
+                	core.sys.posix.unistd.lseek64(hdl, 0, SEEK_SET);
+		}
                 const size_t numRead = core.sys.posix.unistd.read(hdl, _memory, _size);
                 position = 0;
 
