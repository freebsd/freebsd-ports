--- providers/oracle/utils.c.orig	Sat Jul 17 11:07:46 2004
+++ providers/oracle/utils.c	Sat Jul 17 11:08:12 2004
@@ -110,7 +110,7 @@
 			break;
 		case OCI_HTYPE_ENV:
 			gda_connection_add_error (cnc, gda_oracle_make_error (priv_data->henv, type, file, line));
-		default:
+		default: ;
 		}
 		break;
 	default:
