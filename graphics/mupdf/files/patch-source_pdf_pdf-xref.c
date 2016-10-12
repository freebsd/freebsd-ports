$OpenBSD: patch-source_pdf_pdf-xref_c,v 1.1 2016/08/27 20:58:48 jca Exp $

  CVE-2016-6265

  http://git.ghostscript.com/?p=mupdf.git;a=commitdiff;h=fa1936405b6a84e5c9bb440912c23d532772f958

--- source/pdf/pdf-xref.c.orig	2016-04-21 11:14:32 UTC
+++ source/pdf/pdf-xref.c
@@ -1191,8 +1191,14 @@ pdf_load_xref(fz_context *ctx, pdf_docum
 				fz_throw(ctx, FZ_ERROR_GENERIC, "object offset out of range: %d (%d 0 R)", (int)entry->ofs, i);
 		}
 		if (entry->type == 'o')
-			if (entry->ofs <= 0 || entry->ofs >= xref_len || pdf_get_xref_entry(ctx, doc, entry->ofs)->type != 'n')
-				fz_throw(ctx, FZ_ERROR_GENERIC, "invalid reference to an objstm that does not exist: %d (%d 0 R)", (int)entry->ofs, i);
+		{
+			/* Read this into a local variable here, because pdf_get_xref_entry
+			 * may solidify the xref, hence invalidating "entry", meaning we
+			 * need a stashed value for the throw. */
+			fz_off_t ofs = entry->ofs;
+			if (ofs <= 0 || ofs >= xref_len || pdf_get_xref_entry(ctx, doc, ofs)->type != 'n')
+				fz_throw(ctx, FZ_ERROR_GENERIC, "invalid reference to an objstm that does not exist: %d (%d 0 R)", (int)ofs, i);
+		}
 	}
 }
 
