--- server.c.orig	2001-12-16 18:18:45.000000000 +0300
+++ server.c	2013-11-24 22:37:06.306435317 +0400
@@ -907,6 +907,8 @@
 	packet[0]=P_MESSAGE;
 	if (!name){snprintf(packet+1,256,"%s",msg);len=strlen(msg)+1+1;}
 	else {snprintf(packet+1,256,"%s> %s",name,msg);len=strlen(name)+strlen(msg)+1+3;}
+	if (len > 255)
+		len = 255;
 	send_chunk_packet_to_player(packet,len,player);
 }
 
@@ -921,6 +923,8 @@
 	packet[0]=P_MESSAGE;
 	if (!name){snprintf(packet+1,255,"%s",msg);len=strlen(msg)+1+1;}
 	else {snprintf(packet+1,255,"%s> %s",name,msg);len=strlen(name)+strlen(msg)+1+3;}
+	if (len > 255)
+		len = 255;
 	for (p=&players;p->next;p=p->next)
 		if ((!not1||(&(p->next->member))!=not1)&&(!not2||(&(p->next->member))!=not2))
  			send_chunk_packet_to_player(packet,len,&(p->next->member));
@@ -1228,6 +1232,12 @@
 					send_packet(packet,2,(struct sockaddr*)(&client),0,last_player->member.id);
 					break;
 				}
+				if (strlen(packet+5) > MAX_NAME_LEN)
+				{
+					snprintf(txt,256,"Name too long, shortening it to %i characters\n",MAX_NAME_LEN);
+					message(txt,2);
+					packet[5+MAX_NAME_LEN]='\0';
+				}
 				find_birthplace(&x,&y);
 				if (add_player(packet[4],packet+5,&client,x,y)) /* failed to add player */
 				{
