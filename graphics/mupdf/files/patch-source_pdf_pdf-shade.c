$OpenBSD: patch-source_pdf_pdf-shade_c,v 1.1 2016/08/27 20:58:48 jca Exp $

  CVE-2016-6525

  http://git.ghostscript.com/?p=mupdf.git;a=commitdiff;h=39b0f07dd960f34e7e6bf230ffc3d87c41ef0f2e;hp=fa1936405b6a84e5c9bb440912c23d532772f958

--- source/pdf/pdf-shade.c.orig	2016-04-21 11:14:32 UTC
+++ source/pdf/pdf-shade.c
@@ -206,7 +206,7 @@ pdf_load_mesh_params(fz_context *ctx, pd
 	obj = pdf_dict_get(ctx, dict, PDF_NAME_Decode);
 	if (pdf_array_len(ctx, obj) >= 6)
 	{
-		n = (pdf_array_len(ctx, obj) - 4) / 2;
+		n = fz_mini(FZ_MAX_COLORS, (pdf_array_len(ctx, obj) - 4) / 2);
 		shade->u.m.x0 = pdf_to_real(ctx, pdf_array_get(ctx, obj, 0));
 		shade->u.m.x1 = pdf_to_real(ctx, pdf_array_get(ctx, obj, 1));
 		shade->u.m.y0 = pdf_to_real(ctx, pdf_array_get(ctx, obj, 2));
