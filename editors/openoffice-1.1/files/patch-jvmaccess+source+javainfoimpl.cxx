http://qa.openoffice.org/issues/show_bug.cgi?id=40643

Although FreeBSD has its own Java, 1.3.1 and 1.4.2, however,
it is not certified by SUN Microsystems. FreeBSD can use Linux's Java
since there is a binary compatibility (NOT EMULATION!)
Recognize Linux's Java (SUN's, IBM's and Blackdown's) by default,
we need to add several seachpaths.

Index: jvmaccess/source/javainfoimpl.cxx
===================================================================
RCS file: /cvs/udk/jvmaccess/source/Attic/javainfoimpl.cxx,v
retrieving revision 1.7.12.5
diff -u -r1.7.12.5 javainfoimpl.cxx
--- jvmaccess/source/javainfoimpl.cxx	20 Oct 2004 11:43:13 -0000	1.7.12.5
+++ jvmaccess/source/javainfoimpl.cxx	14 Jan 2005 10:58:53 -0000
@@ -240,8 +240,16 @@
                         "java", \
                         "Home", \
                         "IBMJava2-" ARCH "-131", \
-                        "IBMJava2-" ARCH "-141"
-
+                        "IBMJava2-" ARCH "-141" , \
+                        "jdk1.4.2", \
+                        "diablo-jre1.3.1", \
+                        "diablo-jdk1.3.1", \
+                        "linux-sun-jdk1.3.1", \
+                        "linux-sun-jdk1.4.2", \
+                        "linux-ibm-jdk1.3.1", \
+                        "linux-ibm-jdk1.4.2", \
+                        "linux-blackdown-jdk1.3.1", \
+                        "linux-blackdown-jdk1.4.2"
 
 /* These are directories in which a java installation is
    looked for.
