--- code/qcommon/q_shared.c.orig	2011-12-24 12:29:31 UTC
+++ code/qcommon/q_shared.c
@@ -96,6 +96,30 @@ void COM_StripExtension( const char *in,
 		out[length] = 0;
 }
 
+/*
+============
+COM_CompareExtension
+
+string compare the end of the strings and return qtrue if strings match
+============
+*/
+qboolean COM_CompareExtension(const char *in, const char *ext)
+{
+	int inlen, extlen;
+
+	inlen = strlen(in);
+	extlen = strlen(ext);
+
+	if(extlen <= inlen)
+	{
+		in += inlen - extlen;
+
+		if(!Q_stricmp(in, ext))
+			return qtrue;
+	}
+
+	return qfalse;
+}
 
 /*
 ==================
