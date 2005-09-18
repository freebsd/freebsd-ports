--- fracplanet.pro.orig
+++ fracplanet.pro
@@ -1,15 +1,15 @@
 TEMPLATE = app
 
 # append debug or release
-CONFIG+= qt opengl debug # release
+CONFIG+= qt opengl release # debug
 
 #######################################
 # Installation 
 
 INSTALLS += executable documentation
-executable.path = /usr/local/bin
+executable.path = %%PREFIX%%/bin
 executable.files = fracplanet 
-documentation.path = /usr/local/share/doc/fracplanet
+documentation.path = %%DOCSDIR%%
 documentation.files = fracplanet.htm fracplanet.css
 
 ##################
@@ -17,8 +17,8 @@
 # Now leaving these ON for general distribution
 # -funroll-loops unproven 
 
-QMAKE_CXXFLAGS_RELEASE -= -O2
-QMAKE_CXXFLAGS_RELEASE += -O3 -fomit-frame-pointer -ffast-math 
+#QMAKE_CXXFLAGS_RELEASE -= -O2
+#QMAKE_CXXFLAGS_RELEASE += -O3 -fomit-frame-pointer -ffast-math 
 
 ##################
 # Architecture specific optimisations
