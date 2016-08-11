--- tools/autoconf.c.orig	2016-06-20 14:41:27 UTC
+++ tools/autoconf.c
@@ -443,9 +443,9 @@ int main()
 	fprintf(makefile,"INCLUDE = -I./src/ -I.\n");
     fprintf(makefile,"OBJS	= src/psybnc.o src/match.o src/p_client.o src/p_crypt.o src/p_dcc.o src/p_hash.o src/p_idea.o src/p_inifunc.o src/p_link.o src/p_log.o src/p_memory.o src/p_network.o src/p_parse.o src/p_peer.o src/p_server.o src/p_socket.o src/p_string.o src/p_sysmsg.o src/p_userfile.o src/p_uchannel.o src/p_script.o src/p_topology.o src/p_intnet.o src/p_blowfish.o src/p_translate.o src/p_coredns.o src/snprintf.o %s\n",env);
     if(provi==0)
-	fprintf(makefile,"DEFINE	= -DHAVE_CONFIG %s%s%s%s%s%s\n",sunosopt,bigopt,ipv6opt,timeopt,sslopt,dnsopt);
+	fprintf(makefile,"DEFINE	= -DHAVE_CONFIG %s%s%s%s%s%s -DPSYBASE=\\\"%s\\\" -DPREFIX=\\\"%s\\\"\n",sunosopt,bigopt,ipv6opt,timeopt,sslopt,dnsopt, PSYBASE, PREFIX);
     else
-	fprintf(makefile,"DEFINE	= -DHAVE_PROV_CONFIG %s%s%s%s%s%s\n",sunosopt,bigopt,ipv6opt,timeopt,sslopt,dnsopt);
+	fprintf(makefile,"DEFINE	= -DHAVE_PROV_CONFIG %s%s%s%s%s%s -DPSYBASE=\\\"%s\\\" -DPREFIX=\\\"%s\\\"\n",sunosopt,bigopt,ipv6opt,timeopt,sslopt,dnsopt, PSYBASE, PREFIX);
     fprintf(makefile,"TARGET	= psybnc\n");
     fprintf(makefile,"\n");
     fprintf(makefile,"all:	$(OBJS)\n");
@@ -453,7 +453,8 @@ int main()
     fprintf(makefile,"	@strip $(TARGET)\n");
     if(ssl==0)
     {
-	if(!fexists("key/psybnc.cert.pem")) /* only create, if not exist */
+	if(!fexists(PSYBASE "/key/psybnc.cert.pem") && 
+		!fexists("key/psybnc.cert.pem")) /* only create, if not exist */
 	{
 	    mkdir("key",0700);
 	    fprintf(makefile,"	@echo \"*** GENERATING SSL-KEYS FROM CERTIFICATE **\"\n");
