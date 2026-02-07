--- arm_v6_bsd.mk.orig	2016-12-20 09:52:10 UTC
+++ arm_v6_bsd.mk
@@ -0,0 +1,15 @@
+##
+## ARMHF V6 tested on 
+## - Raspberry board -
+##
+## To improve the build speed in small systems disable -pedantic
+## switch in CXXFLAGS
+##
+TargetCPU  :=arm_v6
+OS         :=bsd
+CXXFLAGS   := -O3 -g -fPIC -pedantic
+
+# Standard part
+
+include common.mk
+
