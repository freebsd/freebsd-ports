--- src/fe-gnome/fe-gnome.c.orig	Wed Apr 28 02:38:33 2004
+++ src/fe-gnome/fe-gnome.c	Wed Sep  1 14:16:10 2004
@@ -249,7 +249,7 @@
 			add_transfer(dcc);
 			break;
 
-		default:
+		default: ;
 	}
 }
 
@@ -260,7 +260,7 @@
 			update_transfer(dcc);
 			break;
 
-		default:
+		default: ;
 	}
 }
 
@@ -272,7 +272,7 @@
 			remove_transfer(dcc);
 			break;
 
-		default:
+		default: ;
 	}
 }
 
