--- bforce/prot_yoohoo.c.old	Thu Jul 29 23:39:27 2004
+++ bforce/prot_yoohoo.c	Thu Jul 29 23:40:02 2004
@@ -514,7 +514,7 @@
 		case PROT_ZEDZAP: local_data->capabilities |= YOOHOO_ZEDZAP; break;
 		case PROT_JANUS:  local_data->capabilities |= YOOHOO_JANUS;  break;
 		case PROT_HYDRA:  local_data->capabilities |= YOOHOO_HYDRA;  break;
-		default:          /* Avoid warnings */
+		default:          break;
 		}
 	}
 	
