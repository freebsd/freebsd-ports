--- ../python/makefile.mk	31 Jul 2003 12:15:14 -0000	1.5.2.2
+++ ../python/makefile.mk	8 Aug 2003 15:28:45 -0000
@@ -187,7 +187,7 @@
 	ld -G -o $@ -u Py_Main -u Py_FrozenMain -u PyFPE_dummy $(MISC)$/build$/$(TARFILE_NAME)$/libpython$(PYMAJOR).$(PYMINOR).a -h libpython.so.$(PYMAJOR) -lm -ldl -lc -lpthread
 .ELSE
 .IF "$(OS)" == "FREEBSD"
-	ld -shared -o $@ --whole-archive $(MISC)$/build$/$(TARFILE_NAME)$/libpython$(PYMAJOR).$(PYMINOR).a --no-whole-archive -soname libpython.so.$(PYMAJOR)  -lm -lutil ${PTHREAD_LIBS}
+	$(LINK) -shared -o $@ -Wl,-whole-archive $(MISC)$/build$/$(TARFILE_NAME)$/libpython$(PYMAJOR).$(PYMINOR).a -Wl,-no-whole-archive -soname libpython.so.$(PYMAJOR)  -lm -lutil ${PTHREAD_LIBS}
 .ELSE
 .IF "$(OS)" == "IRIX"
 	ld -shared -o $@ -all $(MISC)$/build$/$(TARFILE_NAME)$/libpython$(PYMAJOR).$(PYMINOR).a -notall -soname libpython.so.$(PYMAJOR)  -lm -ldl -lc -lpthread
