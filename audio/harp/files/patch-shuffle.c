--- shuffle.c.orig	2015-07-24 17:35:12 UTC
+++ shuffle.c
@@ -159,10 +159,7 @@ struct zs_arg{
 	const unsigned int items;
 	const unsigned int group_items;
 	const unsigned int increment;
-	union{
-		const unsigned int skip;
-		const unsigned int slide;
-	};
+	const unsigned int slide;
 	unsigned int count;
 	int slidemod;
 	char *query;
@@ -260,7 +257,7 @@ void zshuffle(unsigned int items){
 	struct candidate_data candlist;
 
 	srandom((unsigned int)time(NULL));
-	struct zs_arg data={.items=items,.group_items=group,.increment=(random()%2)+2,.skip=(random()%3)+2,.count=0,.slidemod=1,.query=cb_query};
+	struct zs_arg data={.items=items,.group_items=group,.increment=(random()%2)+2,.slide=(random()%3)+2,.count=0,.slidemod=1,.query=cb_query};
 
 	sprintf(query,"Mod count: %d\nGroup: %d\nIncrement: %d",mod_count,group,data.increment);
 	debug(2,query);
