--- camel/camel-net-utils.c.orig	Tue Dec 21 13:38:52 2004
+++ camel/camel-net-utils.c	Tue Dec 21 13:40:34 2004
@@ -143,12 +143,21 @@
 	case EAI_SERVICE:
 		return NO_DATA;
 		break;
+#ifdef EAI_ADDRFAMILY
 	case EAI_ADDRFAMILY:
 		return NO_ADDRESS;
 		break;
+#endif
+#if defined(EAI_NODATA) && EAI_NODATA != EAI_NONAME
 	case EAI_NODATA:
 		return NO_DATA;
 		break;
+#endif
+#ifdef EAI_NOFAMILY
+	case EAI_NOFAMILY:
+		return NO_ADDRESS;
+		break;
+#endif
 	case EAI_MEMORY:
 		return ENOMEM;
 		break;
