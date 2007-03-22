--- ref_gl/gl_model.c.orig	Sun Jan  1 15:07:39 2006
+++ ref_gl/gl_model.c	Thu Mar 22 00:33:43 2007
@@ -227,7 +227,7 @@
 	}
 
 
-	out->script = rs = (struct rscript_s *)out->script = RS_FindScript(va("textures/%s",name) );
+	out->script = rs = out->script = RS_FindScript(va("textures/%s",name) );
 	if (rs && rs->picsize.enable)
 	{
 		if (r_numTexSizes < MAX_IMAGES)
@@ -459,7 +459,7 @@
 				while (img != NULL) {
 					strcpy(rs,mod->skins[i]->name);
 					rs[strlen(rs)-4]=0;
-					(struct rscript_s *)mod->script[i] = RS_FindScript(rs);
+					mod->script[i] = RS_FindScript(rs);
 					if (mod->script[i])
 						RS_ReadyScript((rscript_t *)mod->script[i]);
 					i++;
@@ -1374,7 +1374,7 @@
 		strcpy(rs,(char *)pheader + pheader->ofs_skins + i*MAX_SKINNAME);
 
 		rs[strlen(rs)-4]=0;
-		(struct rscript_s *)mod->script[i] = RS_FindScript(rs);
+		mod->script[i] = RS_FindScript(rs);
 		if (mod->script[i])
 			RS_ReadyScript((rscript_t *)mod->script[i]);
 	}
