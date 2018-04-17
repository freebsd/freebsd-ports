--- netdefs/netdefs.c.orig	2016-11-25 19:04:24 UTC
+++ netdefs/netdefs.c
@@ -147,7 +147,7 @@ int main(){
 	printf ("msg_iov_sz=: %d\n",sizeof(((struct msghdr*)0)->msg_iov));
 	printf ("msg_iovlen_off=: %d\n",offset(struct msghdr,msg_iovlen));
 	printf ("msg_iovlen_sz=: %d\n",sizeof(((struct msghdr*)0)->msg_iovlen));
-#if defined(linux) || defined(Darwin)
+#if defined(linux) || defined(Darwin) || defined(__FreeBSD__)
 	printf ("msg_control_off=: %d\n",offset(struct msghdr,msg_control));
 	printf ("msg_control_sz=: %d\n",sizeof(((struct msghdr*)0)->msg_control));
 	printf ("msg_controllen_off=: %d\n",offset(struct msghdr,msg_controllen));
