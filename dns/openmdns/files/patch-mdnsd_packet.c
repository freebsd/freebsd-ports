packet.c:919:22: error: passing 'u_char [64]' to parameter of type 'const char *' converts between
      pointers to integer types with different sign [-Werror=pointer-sign]
                if (strlcat(dname, label, MAXHOSTNAMELEN) >= MAXHOSTNAMELEN)  {
                                   ^~~~~
/usr/include/string.h:92:59: note: passing argument to parameter here
size_t   strlcat(char * __restrict, const char * __restrict, size_t);
                                                           ^
packet.c:986:7: error: assigning to 'char *' from 'u_int8_t *' (aka 'unsigned char *') converts
      between pointers to integer types with different sign [-Werror=pointer-sign]
                buf = *pbuf;
                    ^ ~~~~~
packet.c:1025:7: error: assigning to 'char *' from 'u_int8_t *' (aka 'unsigned char *') converts
      between pointers to integer types with different sign [-Werror=pointer-sign]
                buf = *pbuf;
                    ^ ~~~~~
packet.c:1033:22: error: passing 'char *' to parameter of type 'u_int8_t *' (aka 'unsigned char *')
      converts between pointers to integer types with different sign [-Werror=pointer-sign]
                if (rr_parse_dname(buf, tmplen, rr->rdata.SRV.target) == -1)
                                   ^~~
packet.c:71:32: note: passing argument to parameter here
int              rr_parse_dname(u_int8_t *, u_int16_t, char [MAXHOSTNAMELEN]);
                                          ^
4 errors generated.

--- mdnsd/packet.c.orig	2015-05-29 14:18:11 UTC
+++ mdnsd/packet.c
@@ -853,7 +853,7 @@ pkt_parse_dname(u_int8_t *buf, u_int16_t
 	int jumped = 0;
 	u_int16_t oldlen = len;
 	size_t slen;
-	u_char label[MAXLABELLEN];
+	char label[MAXLABELLEN];
 
 	/* be extra safe */
 	bzero(dname, MAXHOSTNAMELEN);
@@ -948,7 +948,7 @@ pkt_parse_rr(u_int8_t **pbuf, u_int16_t 
 	u_int16_t us, rdlen, tmplen;
 	u_int32_t ul;
 	ssize_t n;
-	char *buf;
+	u_char *buf;
 
 	n = pkt_parse_dname(*pbuf, *len, rr->rrs.dname);
 	if (n == -1)
