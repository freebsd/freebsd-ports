--- netdefs/netdefs.c.orig	2019-01-06 15:19:53 UTC
+++ netdefs/netdefs.c
@@ -152,7 +152,7 @@ int main(){
 	printf ("msg_iov_sz=: " FMTI "\n",sizeof(((struct msghdr*)0)->msg_iov));
 	printf ("msg_iovlen_off=: " FMTI "\n",offset(struct msghdr,msg_iovlen));
 	printf ("msg_iovlen_sz=: " FMTI "\n",sizeof(((struct msghdr*)0)->msg_iovlen));
-#if defined(linux) || defined(Darwin)
+#if defined(linux) || defined(Darwin) || defined(__FreeBSD__)
 	printf ("msg_control_off=: " FMTI "\n",offset(struct msghdr,msg_control));
 	printf ("msg_control_sz=: " FMTI "\n",sizeof(((struct msghdr*)0)->msg_control));
 	printf ("msg_controllen_off=: " FMTI "\n",offset(struct msghdr,msg_controllen));
