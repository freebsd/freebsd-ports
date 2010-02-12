--- src/MULTIPR/MULTIPR_Field.cxx.orig	2009-03-18 20:52:30.000000000 +0600
+++ src/MULTIPR/MULTIPR_Field.cxx	2009-06-05 14:47:48.000000000 +0700
@@ -832,7 +832,7 @@
 	}
 }
 
-ostream& operator<<(ostream& pOs, Field& pF)
+std::ostream& operator<<(std::ostream& pOs, Field& pF)
 {
     char strEntity[16];
     switch (pF.mEntity) 
