Issuetracker : #i54178#
CWS          : hr17
Author:      :
Description  :

Index: rsc/source/rscpp/makefile.mk
===================================================================
RCS file: /cvs/gsl/rsc/source/rscpp/makefile.mk,v
retrieving revision 1.5
diff -u -r1.5 makefile.mk
--- rsc/source/rscpp/makefile.mk	8 Sep 2005 14:00:27 -0000	1.5
+++ rsc/source/rscpp/makefile.mk	21 Sep 2005 10:18:09 -0000
@@ -36,6 +36,8 @@
 
 TARGETTYPE=CUI
 TARGETTHREAD=ST
+# we don't need STL in this project
+NO_DEFAULT_STL=TRUE
 
 PRJNAME=rsc
 TARGET=rscpp
