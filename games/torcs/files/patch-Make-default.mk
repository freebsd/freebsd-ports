--- Make-default.mk.orig	Sat Apr 19 11:46:59 2003
+++ Make-default.mk	Sat Apr 26 23:47:15 2003
@@ -401,8 +401,8 @@
 	@createdir="${INSTBINBASE}/${TOOLSDIR}" ; \
 	$(mkinstalldirs) $$createdir ; \
 	X="${TOOLSCRIPT}" ; \
-	echo " $(INSTALL_PROGRAM) $$X $$createdir/$$X"; \
-	$(INSTALL_PROGRAM) $$X $$createdir/$$X
+	echo " $(INSTALL_SCRIPT) $$X $$createdir/$$X"; \
+	$(INSTALL_SCRIPT) $$X $$createdir/$$X
 
 else
 
@@ -435,7 +435,7 @@
 ifdef SOLIBRARY
 
 ${SOLIBRARY}: ${OBJECTS}
-	${CXX} -shared -o ${SOLIBRARY} ${OBJECTS} ${LIBSPATH} ${LIBS} ${DEBUG_LIBS}
+	${CXX} -shared -o ${SOLIBRARY} ${OBJECTS} ${LDFLAGS} ${LIBSPATH} ${LIBS} ${DEBUG_LIBS}
 	@D=`pwd` ; \
 	createdir="${EXPORTBASE}/lib" ; \
 	$(mkinstalldirs) $$createdir ; \
@@ -466,7 +466,7 @@
 ifdef MODULE
 
 ${MODULE}: ${OBJECTS}
-	${CXX} -shared -o ${MODULE} ${OBJECTS} ${LIBSPATH} ${LIBS} 
+	${CXX} -shared -o ${MODULE} ${OBJECTS} ${LDFLAGS} ${LIBSPATH} ${LIBS} 
 	@D=`pwd` ; \
 	createdir="${EXPORTBASE}/${MODULEDIR}" ; \
 	$(mkinstalldirs) $$createdir ; \
@@ -719,6 +719,7 @@
 	echo "        cp -f \$$1/${SHIPDIR}/$$C \$$1/${SHIPDIR}/$$C.old" >> ${SETUP_LINUX} ; \
 	echo "    fi" >> ${SETUP_LINUX} ; \
 	echo "    cp -f ${SHIPDIR}/$$C \$$1/${SHIPDIR}/$$C" >> ${SETUP_LINUX} ; \
+	echo "    chmod 640 \$$1/${SHIPDIR}/$$C" >> ${SETUP_LINUX} ; \
 	echo "fi" >> ${SETUP_LINUX} ; \
 	done
 
