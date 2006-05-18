--- ./server/sv_user.c.orig	Tue May 16 15:20:10 2006
+++ ./server/sv_user.c	Tue May 16 15:20:10 2006
@@ -142,6 +142,9 @@
 	}
 	
 	start = atoi(Cmd_Argv(2));
+	if( start < 0 ) {
+		start = 0;	// sku - catch negative offsets
+	}
 
 	// write a packet full of data
 
@@ -150,9 +153,18 @@
 	{
 		if (sv.configstrings[start][0])
 		{
+			int length;
+
+			// sku - write configstrings that exceed MAX_QPATH in proper-sized chunks
+			length = strlen( sv.configstrings[start] );
+			if( length > MAX_QPATH ) {
+				length = MAX_QPATH;
+			}
+
 			MSG_WriteByte (&sv_client->netchan.message, svc_configstring);
 			MSG_WriteShort (&sv_client->netchan.message, start);
-			MSG_WriteString (&sv_client->netchan.message, sv.configstrings[start]);
+			SZ_Write (&sv_client->netchan.message, sv.configstrings[start], length);
+			MSG_WriteByte (&sv_client->netchan.message, 0);
 		}
 		start++;
 	}
@@ -199,6 +211,9 @@
 	}
 	
 	start = atoi(Cmd_Argv(2));
+	if( start < 0 ) {
+		start = 0;
+	}
 
 	memset (&nullstate, 0, sizeof(nullstate));
 
@@ -399,7 +414,7 @@
 */
 void SV_ShowServerinfo_f (void)
 {
-	Info_Print (Cvar_Serverinfo());
+//	Info_Print (Cvar_Serverinfo());
 }
 
 
