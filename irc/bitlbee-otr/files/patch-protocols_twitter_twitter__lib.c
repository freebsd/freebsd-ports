
$FreeBSD$

--- protocols/twitter/twitter_lib.c.orig
+++ protocols/twitter/twitter_lib.c
@@ -77,7 +77,8 @@
 static void txs_free(struct twitter_xml_status *txs)
 {
 	g_free(txs->text);
-	txu_free(txs->user);
+	if(txs->user)
+		txu_free(txs->user);
 	g_free(txs);
 }
 
@@ -472,19 +473,22 @@
 	for ( l = list; l ; l = g_slist_next(l) )
 	{
 		status = l->data;
-		twitter_add_buddy(ic, status->user->screen_name, status->user->name);
-		
-		strip_html(status->text);
+		if(status->user)
+		{
+			twitter_add_buddy(ic, status->user->screen_name, status->user->name);
 		
-		// Say it!
-		if (g_strcasecmp(td->user, status->user->screen_name) == 0)
-			imcb_chat_log (gc, "Your Tweet: %s", status->text);
-		else
-			imcb_chat_msg (gc, status->user->screen_name, status->text, 0, status->created_at );
+			strip_html(status->text);
 		
-		// Update the home_timeline_id to hold the highest id, so that by the next request
-		// we won't pick up the updates allready in the list.
-		td->home_timeline_id = td->home_timeline_id < status->id ? status->id : td->home_timeline_id;
+			// Say it!
+			if (g_strcasecmp(td->user, status->user->screen_name) == 0)
+				imcb_chat_log (gc, "Your Tweet: %s", status->text);
+			else
+				imcb_chat_msg (gc, status->user->screen_name, status->text, 0, status->created_at );
+			
+			// Update the home_timeline_id to hold the highest id, so that by the next request
+			// we won't pick up the updates allready in the list.
+			td->home_timeline_id = td->home_timeline_id < status->id ? status->id : td->home_timeline_id;
+		}
 	}
 }
 
@@ -735,4 +739,4 @@
 	args[0] = "screen_name";
 	args[1] = who;
 	twitter_http(ic, create ? TWITTER_FRIENDSHIPS_CREATE_URL : TWITTER_FRIENDSHIPS_DESTROY_URL, twitter_http_post, ic, 1, args, 2);
-}
\ No newline at end of file
+}
