--- src/input.c.orig	2014-11-28 22:57:48 UTC
+++ src/input.c
@@ -4264,7 +4264,7 @@ filter (MInputContext *ic, MSymbol key, 
   if (ic_info->commit_key_head > 0)
     {
       memmove (ic_info->keys, ic_info->keys + ic_info->commit_key_head,
-	       sizeof (int) * (ic_info->used - ic_info->commit_key_head));
+	       sizeof (MSymbol *) * (ic_info->used - ic_info->commit_key_head));
       ic_info->used -= ic_info->commit_key_head;
       ic_info->key_head -= ic_info->commit_key_head;
       ic_info->state_key_head -= ic_info->commit_key_head;
@@ -4278,7 +4278,7 @@ filter (MInputContext *ic, MSymbol key, 
       if (ic_info->key_head > 0)
 	{
 	  memmove (ic_info->keys, ic_info->keys + ic_info->key_head,
-		   sizeof (int) * (ic_info->used - ic_info->key_head));
+		   sizeof (MSymbol *) * (ic_info->used - ic_info->key_head));
 	  ic_info->used -= ic_info->key_head;
 	  ic_info->key_head = ic_info->state_key_head
 	    = ic_info->commit_key_head = 0;
