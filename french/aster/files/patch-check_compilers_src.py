--- check_compilers_src.py.orig	2013-01-28 13:35:55.000000000 +0100
+++ check_compilers_src.py	2013-03-17 21:11:35.000000000 +0100
@@ -109,12 +109,15 @@
 You must choose another compiler or change the optimization level.
 You can cancel now or make the changes later in the config.txt file of
 Code_Aster and rebuild it.
+
+About volatile patch:
+   see http://www.code-aster.org/forum2/viewtopic.php?pid=40694#p40694
 -------------------------------------------------------------------------------
 
 """,
    'main.f' : r"""
       program testloc
-      volatile ius
+C     volatile ius
       integer*8 ius(1)
       integer*8 i,iad,n,loc
       common /jvcomm/ ius
