--- net.c.orig	2008-11-21 00:18:27.000000000 +0800
+++ net.c	2008-11-21 00:18:47.000000000 +0800
@@ -1134,6 +1134,7 @@
 			free(cmsg);
 			return;
 		}
+#ifdef SCM_CREDENTIALS
 		if (cmsg->cmsg_type == SCM_CREDENTIALS
 		    && CMSG_LEN(sizeof(struct ucred)) <= cmsg_len) {
 			struct ucred *uc = (struct ucred *) CMSG_DATA (cmsg);
@@ -1143,6 +1144,7 @@
 			free(cmsg);
 			return;
 		}
+#endif
 	}
 	free(cmsg);
 	tprintf(", ...}");
