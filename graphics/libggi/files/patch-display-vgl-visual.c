--- display/vgl/visual.c	2005/07/30 11:38:52	1.9
+++ display/vgl/visual.c	2006/10/04 17:42:04	1.9.2.1
@@ -1,4 +1,4 @@
-/* $Id: visual.c,v 1.9 2005/07/30 11:38:52 cegger Exp $
+/* $Id: visual.c,v 1.9.2.1 2006/10/04 17:42:04 cegger Exp $
 ******************************************************************************
 
    FreeBSD vgl(3) target: initialization
@@ -210,13 +210,12 @@
 		error = GGI_ENOMEM;
 		goto error;
 	}
-	VGL_PRIV(vis) = malloc(sizeof(struct vgl_priv));
-	if (VGL_PRIV(vis) == NULL) {
+	LIBGGI_PRIVATE(vis) = priv = malloc(sizeof(struct vgl_priv));
+	if (priv == NULL) {
 		do_cleanup(vis);
 		error = GGI_ENOMEM;
 		goto error;
 	}
-	priv = VGL_PRIV(vis);
 	memset(priv, 0, sizeof(*priv));
 
 	memset(priv->vgl_palred, 0, sizeof(priv->vgl_palred));
