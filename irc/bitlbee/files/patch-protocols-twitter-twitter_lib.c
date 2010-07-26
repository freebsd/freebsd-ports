--- protocols/twitter/twitter_lib.c.orig	2010-07-04 17:26:16.000000000 +0000
+++ protocols/twitter/twitter_lib.c	2010-07-26 11:39:17.000000000 +0000
@@ -65,6 +65,8 @@ static void twitter_groupchat_init(struc
  */
 static void txu_free(struct twitter_xml_user *txu)
 {
+	if (txu == NULL)
+		return;
 	g_free(txu->name);
 	g_free(txu->screen_name);
 	g_free(txu);
@@ -88,6 +90,8 @@ static void txs_free(struct twitter_xml_
 static void txl_free(struct twitter_xml_list *txl)
 {
 	GSList *l;
+	if (txl == NULL)
+		return;
 	for ( l = txl->list; l ; l = g_slist_next(l) )
 		if (txl->type == TXL_STATUS)
 			txs_free((struct twitter_xml_status *)l->data);
@@ -472,6 +476,9 @@ static void twitter_groupchat(struct im_
 	for ( l = list; l ; l = g_slist_next(l) )
 	{
 		status = l->data;
+		if (status->user == NULL || status->text == NULL)
+			continue;
+
 		twitter_add_buddy(ic, status->user->screen_name, status->user->name);
 		
 		strip_html(status->text);
@@ -735,4 +742,4 @@ void twitter_friendships_create_destroy(
 	args[0] = "screen_name";
 	args[1] = who;
 	twitter_http(ic, create ? TWITTER_FRIENDSHIPS_CREATE_URL : TWITTER_FRIENDSHIPS_DESTROY_URL, twitter_http_post, ic, 1, args, 2);
-}
\ No newline at end of file
+}
