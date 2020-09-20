--- Src/chirps_rcv.c.orig	2005-05-19 20:32:10 UTC
+++ Src/chirps_rcv.c
@@ -3,6 +3,10 @@
 
 extern void sig_alrm(int signo);
 
+union {
+  struct cmsghdr cm;
+  char control[CMSG_SPACE(sizeof(struct timeval))];
+} control_un;
 
 /* recording contents of packet. Using inline to make code run faster */
 inline void update_info(u_int32_t nc,u_int32_t np,double snd_time,double rcv_time,u_int32_t pkt_req_num,int good_jumbo_pkt)
