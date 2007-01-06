--- providers/gda-mysql-server/gda-mysql-connection.c.orig	Wed Jan  3 17:18:46 2007
+++ providers/gda-mysql-server/gda-mysql-connection.c	Wed Jan  3 17:18:50 2007
@@ -540,6 +540,7 @@
 				/* N/A */
 				break;
 			default:
+				break;
 			}
 		}
 
@@ -684,6 +685,7 @@
 		case GDA_Connection_COLUMN_NAME:
 			break;
 		default:
+			break;
 		}
 	}
 
