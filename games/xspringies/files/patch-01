--- phys.c.orig	Mon Mar 29 06:26:52 1993
+++ phys.c	Sat Feb 15 16:54:26 1997
@@ -212,11 +212,15 @@
 		
 		mass1 = m1->mass;
 		mass2 = m2->mass;
-		
-		m1->ax += forcex / mass1;
-		m1->ay += forcey / mass1;
-		m2->ax -= forcex / mass2;
-		m2->ay -= forcey / mass2;
+
+		if (mass1 != 0) {
+			m1->ax += forcex / mass1;
+			m1->ay += forcey / mass1;
+		}
+		if (mass2 != 0) {
+			m2->ax -= forcex / mass2;
+			m2->ay -= forcey / mass2;
+		}
 	    }
 	}
     }
