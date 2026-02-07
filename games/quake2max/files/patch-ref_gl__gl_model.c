--- ref_gl/gl_model.c.orig	2006-01-01 18:07:39 UTC
+++ ref_gl/gl_model.c
@@ -227,7 +227,7 @@ static void R_GetTexSize (char *name, mtexinfo_t *out)
 	}
 
 
-	out->script = rs = (struct rscript_s *)out->script = RS_FindScript(va("textures/%s",name) );
+	out->script = rs = out->script = RS_FindScript(va("textures/%s",name) );
 	if (rs && rs->picsize.enable)
 	{
 		if (r_numTexSizes < MAX_IMAGES)
@@ -459,7 +459,7 @@ model_t *Mod_ForName (const char *name, qboolean crash
 				while (img != NULL) {
 					strcpy(rs,mod->skins[i]->name);
 					rs[strlen(rs)-4]=0;
-					(struct rscript_s *)mod->script[i] = RS_FindScript(rs);
+					mod->script[i] = RS_FindScript(rs);
 					if (mod->script[i])
 						RS_ReadyScript((rscript_t *)mod->script[i]);
 					i++;
@@ -1374,7 +1374,7 @@ void Mod_LoadAliasModel (model_t *mod, void *buffer)
 		strcpy(rs,(char *)pheader + pheader->ofs_skins + i*MAX_SKINNAME);
 
 		rs[strlen(rs)-4]=0;
-		(struct rscript_s *)mod->script[i] = RS_FindScript(rs);
+		mod->script[i] = RS_FindScript(rs);
 		if (mod->script[i])
 			RS_ReadyScript((rscript_t *)mod->script[i]);
 	}
@@ -1465,7 +1465,7 @@ void R_BeginRegistration (char *model)
 }
 
 
-signed int *Mod_GetTris(short p1, short p2, dtriangle_t *side1, dmdl_t *hdr)
+static signed int Mod_GetTris(short p1, short p2, dtriangle_t *side1, dmdl_t *hdr)
 {
 	dtriangle_t *tris = (dtriangle_t *)((unsigned char*)hdr + hdr->ofs_tris);
 	int i;
