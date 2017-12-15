--- src/dynamic.c.orig	2000-10-28 11:45:50 UTC
+++ src/dynamic.c
@@ -13,7 +13,8 @@ void dynamic_changing_of_weights(int i, 
 	char c, *str;
 	if(i%divisor==0)
 	{
-		str=string(0L,100L);
+#define MAXINPUTLINE 100L
+		str=string(0L,MAXINPUTLINE);
 		if((fopen("change","rt"))!=NULL)
 		{
 			system("rm change");
@@ -23,24 +24,24 @@ void dynamic_changing_of_weights(int i, 
 			{
 				case 'G':
 				printf("Enter new weight for gain -current weight=%f\n",weight->gain);
-				scanf("%s",str);
+				fgets(str, MAXINPUTLINE-1, stdin);
 				weight->gain=atof(str);
 				fflush(stdin);
 				break;
 
 				case 'F':
 				printf("Enter new weight for FB -current weight=%f\n",weight->fb);
-				gets(str);
+				fgets(str, MAXINPUTLINE-1, stdin);
 				weight->fb=atof(str);
 				break;
 
 				case 'P':
 				printf("Enter new weight for sidelobe -current weight=%f\n",weight->sidelobe);
-				gets(str);
+				fgets(str, MAXINPUTLINE-1, stdin);
 				weight->sidelobe=atof(str);
 				break;
 			} /* end of switch statement */
 		} /* end of if file exits/user hit keyboard */
-	free_string(str,0L,100L);
+	free_string(str,0L,MAXINPUTLINE);
 	} /* end of if divisor%10==0 */
 } /* function  */
