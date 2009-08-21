--- newlib/libc/sys/psp/socket.c.orig	1970-01-01 02:00:00.000000000 +0200
+++ newlib/libc/sys/psp/socket.c	2007-06-01 12:22:26.000000000 +0300
@@ -0,0 +1,390 @@
+/*
+ * PSP Software Development Kit - http://www.pspdev.org
+ * -----------------------------------------------------------------------
+ * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
+ *
+ * socket.c - Socket wrappers to provide similar functions to normal unix
+ *
+ * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
+ * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
+ * 
+ */
+#include <fcntl.h>
+#include <errno.h>
+#include <sys/socket.h>
+#include <sys/select.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+
+#include <psptypes.h>
+#include "fdman.h"
+
+#ifdef F_socket
+int	socket(int domain, int type, int protocol)
+{
+	int sock, scesock;
+	int i;
+
+	scesock = sceNetInetSocket(domain, type, protocol);
+	if(scesock < 0)	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+
+	sock = __psp_fdman_get_new_descriptor();
+	if( sock != -1 )	{
+		__psp_descriptormap[sock]->sce_descriptor = scesock;
+		__psp_descriptormap[sock]->type = __PSP_DESCRIPTOR_TYPE_SOCKET;
+	}
+	else {
+		sceNetInetClose(scesock);
+		errno = ENOENT;
+		return -1;
+	}
+
+	return sock;
+}
+
+/* These are glue routines that are called from _close(), _read(), and
+   _write().  They are here so that any program that uses socket() will pull
+   them in and have expanded socket capability. */
+
+int __psp_socket_close(int sock)
+{
+	int ret = 0;
+
+	if (__psp_descriptormap[sock]->ref_count == 1) {
+		ret = sceNetInetClose(__psp_descriptormap[sock]->sce_descriptor);
+	}
+
+	__psp_fdman_release_descriptor(sock);
+
+	if(ret < 0)
+	{
+		/* If close is defined likely errno is */
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+
+	return 0;
+}
+
+ssize_t __psp_socket_recv(int s, void *buf, size_t len, int flags)
+{
+	return recv(s, buf, len, flags);
+}
+
+ssize_t __psp_socket_send(int s, const void *buf, size_t len, int flags)
+{
+	return send(s, buf, len, flags);
+}
+#endif
+
+#ifdef F_accept
+int	accept(int s, struct sockaddr *addr, socklen_t *addrlen)
+{
+	int newscesock, newsock;
+
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	newscesock = sceNetInetAccept(__psp_descriptormap[s]->sce_descriptor, addr, addrlen);
+	if( (newscesock >= 0) ) {
+		newsock = __psp_fdman_get_new_descriptor();
+		if ( newsock != -1 ) {
+			__psp_descriptormap[newsock]->sce_descriptor = newscesock;
+			__psp_descriptormap[newsock]->type = __PSP_DESCRIPTOR_TYPE_SOCKET;
+		}
+		else {
+			sceNetInetClose(newscesock);
+			errno = ENOENT;
+			return -1;
+		}
+	}
+	else {
+		errno = ENOENT;
+		return -1;
+	}
+
+	return newsock;
+}
+#endif
+
+#ifdef F_bind
+int	bind(int s, const struct sockaddr *my_addr, socklen_t addrlen)
+{
+	int ret;
+	
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	ret = sceNetInetBind(__psp_descriptormap[s]->sce_descriptor, my_addr, addrlen);
+	if(ret < 0)
+	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+
+	return 0;
+}
+#endif
+
+#ifdef F_connect
+int	connect(int s, const struct sockaddr *serv_addr, socklen_t addrlen)
+{
+	int ret;
+
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	ret = sceNetInetConnect(__psp_descriptormap[s]->sce_descriptor, serv_addr, addrlen);
+	if(ret < 0)
+	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+	
+	return 0;
+}
+#endif
+
+#ifdef F_setsockopt
+int	getsockopt(int s, int level, int optname, void *optval, socklen_t *optlen)
+{
+	int ret;
+
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	ret = sceNetInetGetsockopt(__psp_descriptormap[s]->sce_descriptor, level, optname, optval, optlen);
+	if(ret < 0)
+	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+	
+	return 0;
+}
+#endif
+
+#ifdef F_listen
+int	listen(int s, int backlog)
+{
+	int ret;
+
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	ret = sceNetInetListen(__psp_descriptormap[s]->sce_descriptor, backlog);
+	if(ret < 0)
+	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+
+	return 0;
+}
+#endif
+
+#ifdef F_recv
+ssize_t	recv(int s, void *buf, size_t len, int flags)
+{
+	int ret;
+
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	ret = sceNetInetRecv(__psp_descriptormap[s]->sce_descriptor, buf, len, flags);
+	if(ret < 0)
+	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+
+	return ret;
+}
+#endif
+
+#ifdef F_recvfrom
+ssize_t	recvfrom(int s, void *buf, size_t len, int flags, struct sockaddr *from, socklen_t *fromlen)
+{
+	int ret;
+
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	ret = sceNetInetRecvfrom(__psp_descriptormap[s]->sce_descriptor, buf, len, flags, from, fromlen);
+	if(ret < 0)
+	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+
+	return ret;
+}
+#endif
+
+#ifdef F_send
+ssize_t	send(int s, const void *buf, size_t len, int flags)
+{
+	int ret;
+
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	ret = sceNetInetSend(__psp_descriptormap[s]->sce_descriptor, buf, len, flags);
+	if(ret < 0)
+	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+
+	return ret;
+}
+#endif
+
+#ifdef F_sendto
+ssize_t	sendto(int s, const void *buf, size_t len, int flags, const struct sockaddr *to, socklen_t tolen)
+{
+	int ret;
+
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	ret = sceNetInetSendto(__psp_descriptormap[s]->sce_descriptor, buf, len, flags, to, tolen);
+	if(ret < 0)
+	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+
+	return ret;
+}
+#endif
+
+#ifdef F_setsockopt
+int	setsockopt(int s, int level, int optname, const void *optval, socklen_t optlen)
+{
+	int ret;
+
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	ret = sceNetInetSetsockopt(__psp_descriptormap[s]->sce_descriptor, level, optname, optval, optlen);
+	if(ret < 0)
+	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+	else
+	{
+		if ( (level == SOL_SOCKET) && (optname == SO_NONBLOCK) ) {
+			if (*((int*)optval) == 1) {
+				__psp_descriptormap[s]->flags |= O_NONBLOCK;
+			}
+			else {
+				__psp_descriptormap[s]->flags &= ~O_NONBLOCK;
+			}	
+		}
+	}
+
+	return 0;
+}
+#endif
+
+#ifdef F_shutdown
+int	shutdown(int s, int how)
+{
+	int ret;
+
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	ret = sceNetInetShutdown(__psp_descriptormap[s]->sce_descriptor, how);
+	if(ret < 0)
+	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+
+	return 0;
+}
+#endif
+
+#ifdef F_getpeername
+int	getpeername(int s, struct sockaddr *name, socklen_t *namelen)
+{
+	int ret;
+
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	ret = sceNetInetGetpeername(__psp_descriptormap[s]->sce_descriptor, name, namelen);
+	if(ret < 0)
+	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+
+	return 0;
+}
+#endif
+
+#ifdef F_getsockname
+int	getsockname(int s, struct sockaddr *name, socklen_t *namelen)
+{
+	int ret;
+
+	if (!__PSP_IS_FD_OF_TYPE(s, __PSP_DESCRIPTOR_TYPE_SOCKET)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	ret = sceNetInetGetsockname(__psp_descriptormap[s]->sce_descriptor, name, namelen);
+	if(ret < 0)
+	{
+		errno = sceNetInetGetErrno();
+		return -1;
+	}
+
+	return 0;
+}
+#endif
+
+#ifdef F_inet_ntoa
+char *inet_ntoa(struct in_addr in)
+{
+	static char ip_addr[INET_ADDRSTRLEN+1];
+
+	if(sceNetInetInetNtop(AF_INET, &in, ip_addr, INET_ADDRSTRLEN) == NULL)
+	{
+		strcpy(ip_addr, "Invalid");
+	}
+
+	return ip_addr;
+}
+#endif
