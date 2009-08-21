--- newlib/libc/sys/psp/sys/socket.h.orig	1970-01-01 02:00:00.000000000 +0200
+++ newlib/libc/sys/psp/sys/socket.h	2007-06-01 12:22:26.000000000 +0300
@@ -0,0 +1,294 @@
+/*	$NetBSD: socket.h,v 1.77 2005/11/29 03:12:16 christos Exp $	*/
+
+/*
+ * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.
+ * All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. Neither the name of the project nor the names of its contributors
+ *    may be used to endorse or promote products derived from this software
+ *    without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ */
+
+/*
+ * Copyright (c) 1982, 1985, 1986, 1988, 1993, 1994
+ *	The Regents of the University of California.  All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. Neither the name of the University nor the names of its contributors
+ *    may be used to endorse or promote products derived from this software
+ *    without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ *
+ *	@(#)socket.h	8.6 (Berkeley) 5/3/95
+ */
+
+#ifndef _SYS_SOCKET_H_
+#define	_SYS_SOCKET_H_
+
+#ifdef __cplusplus
+extern "C" {
+#endif
+
+#include <stdint.h>
+#include <stddef.h>
+#include <sys/types.h>
+
+typedef uint8_t sa_family_t;
+typedef uint32_t socklen_t;
+
+/*
+ * Socket types.
+ */
+#define	SOCK_STREAM	1		/* stream socket */
+#define	SOCK_DGRAM	2		/* datagram socket */
+#define	SOCK_RAW	3		/* raw-protocol interface */
+#define	SOCK_RDM	4		/* reliably-delivered message */
+#define	SOCK_SEQPACKET	5		/* sequenced packet stream */
+
+/*
+ * Option flags per-socket.
+ */
+#define	SO_DEBUG	0x0001		/* turn on debugging info recording */
+#define	SO_ACCEPTCONN	0x0002		/* socket has had listen() */
+#define	SO_REUSEADDR	0x0004		/* allow local address reuse */
+#define	SO_KEEPALIVE	0x0008		/* keep connections alive */
+#define	SO_DONTROUTE	0x0010		/* just use interface addresses */
+#define	SO_BROADCAST	0x0020		/* permit sending of broadcast msgs */
+#define	SO_USELOOPBACK	0x0040		/* bypass hardware when possible */
+#define	SO_LINGER	0x0080		/* linger on close if data present */
+#define	SO_OOBINLINE	0x0100		/* leave received OOB data in line */
+#define	SO_REUSEPORT	0x0200		/* allow local address & port reuse */
+#define	SO_TIMESTAMP	0x0400		/* timestamp received dgram traffic */
+
+/*
+ * Additional options, not kept in so_options.
+ */
+#define SO_SNDBUF	0x1001		/* send buffer size */
+#define SO_RCVBUF	0x1002		/* receive buffer size */
+#define SO_SNDLOWAT	0x1003		/* send low-water mark */
+#define SO_RCVLOWAT	0x1004		/* receive low-water mark */
+#define SO_SNDTIMEO	0x1005		/* send timeout */
+#define SO_RCVTIMEO	0x1006		/* receive timeout */
+#define	SO_ERROR	0x1007		/* get error status and clear */
+#define	SO_TYPE		0x1008		/* get socket type */
+#define	SO_OVERFLOWED	0x1009		/* datagrams: return packets dropped */
+#define	SO_NONBLOCK     0x1009		/* non-blocking I/O */
+
+/*
+ * Structure used for manipulating linger option.
+ */
+struct	linger {
+	int	l_onoff;		/* option on/off */
+	int	l_linger;		/* linger time in seconds */
+};
+
+/*
+ * Level number for (get/set)sockopt() to apply to socket itself.
+ */
+#define	SOL_SOCKET	0xffff		/* options for socket level */
+
+/*
+ * Address families.
+ */
+#define	AF_UNSPEC	0		/* unspecified */
+#define	AF_LOCAL	1		/* local to host (pipes, portals) */
+#define	AF_UNIX		AF_LOCAL	/* backward compatibility */
+#define	AF_INET		2		/* internetwork: UDP, TCP, etc. */
+#define	AF_IMPLINK	3		/* arpanet imp addresses */
+#define	AF_PUP		4		/* pup protocols: e.g. BSP */
+#define	AF_CHAOS	5		/* mit CHAOS protocols */
+#define	AF_NS		6		/* XEROX NS protocols */
+#define	AF_ISO		7		/* ISO protocols */
+#define	AF_OSI		AF_ISO
+#define	AF_ECMA		8		/* european computer manufacturers */
+#define	AF_DATAKIT	9		/* datakit protocols */
+#define	AF_CCITT	10		/* CCITT protocols, X.25 etc */
+#define	AF_SNA		11		/* IBM SNA */
+#define AF_DECnet	12		/* DECnet */
+#define AF_DLI		13		/* DEC Direct data link interface */
+#define AF_LAT		14		/* LAT */
+#define	AF_HYLINK	15		/* NSC Hyperchannel */
+#define	AF_APPLETALK	16		/* Apple Talk */
+#define	AF_ROUTE	17		/* Internal Routing Protocol */
+#define	AF_LINK		18		/* Link layer interface */
+#define	AF_COIP		20		/* connection-oriented IP, aka ST II */
+#define	AF_CNT		21		/* Computer Network Technology */
+#define	AF_IPX		23		/* Novell Internet Protocol */
+#define	AF_INET6	24		/* IP version 6 */
+#define AF_ISDN		26		/* Integrated Services Digital Network*/
+#define AF_E164		AF_ISDN		/* CCITT E.164 recommendation */
+#define AF_NATM		27		/* native ATM access */
+#define AF_ARP		28		/* (rev.) addr. res. prot. (RFC 826) */
+#define	AF_MAX		31
+
+/*
+ * Structure used by kernel to store most
+ * addresses.
+ */
+struct sockaddr {
+	uint8_t	sa_len;		/* total length */
+	sa_family_t	sa_family;	/* address family */
+	char		sa_data[14];	/* actually longer; address value */
+};
+
+/*
+ * Protocol families, same as address families for now.
+ */
+#define	PF_UNSPEC	AF_UNSPEC
+#define	PF_LOCAL	AF_LOCAL
+#define	PF_UNIX		PF_LOCAL	/* backward compatibility */
+#define	PF_INET		AF_INET
+#define	PF_IMPLINK	AF_IMPLINK
+#define	PF_PUP		AF_PUP
+#define	PF_CHAOS	AF_CHAOS
+#define	PF_NS		AF_NS
+#define	PF_ISO		AF_ISO
+#define	PF_OSI		AF_ISO
+#define	PF_ECMA		AF_ECMA
+#define	PF_DATAKIT	AF_DATAKIT
+#define	PF_CCITT	AF_CCITT
+#define	PF_SNA		AF_SNA
+#define PF_DECnet	AF_DECnet
+#define PF_DLI		AF_DLI
+#define PF_LAT		AF_LAT
+#define	PF_HYLINK	AF_HYLINK
+#define	PF_APPLETALK	AF_APPLETALK
+#define	PF_ROUTE	AF_ROUTE
+#define	PF_LINK		AF_LINK
+#if defined(_NETBSD_SOURCE)
+#define	PF_XTP		pseudo_AF_XTP	/* really just proto family, no AF */
+#endif
+#define	PF_COIP		AF_COIP
+#define	PF_CNT		AF_CNT
+#define	PF_INET6	AF_INET6
+#define	PF_IPX		AF_IPX		/* same format as AF_NS */
+#if defined(_NETBSD_SOURCE)
+#define PF_RTIP		pseudo_AF_RTIP	/* same format as AF_INET */
+#define PF_PIP		pseudo_AF_PIP
+#endif
+#define PF_ISDN		AF_ISDN		/* same as E164 */
+#define PF_E164		AF_E164
+#define PF_NATM		AF_NATM
+#define PF_ARP		AF_ARP
+#if defined(_NETBSD_SOURCE)
+#define PF_KEY 		pseudo_AF_KEY	/* like PF_ROUTE, only for key mgmt */
+#endif
+
+#define	PF_MAX		AF_MAX
+
+#define	MSG_OOB		0x1		/* process out-of-band data */
+#define	MSG_PEEK	0x2		/* peek at incoming message */
+#define	MSG_DONTROUTE	0x4		/* send without using routing tables */
+#define	MSG_EOR		0x8		/* data completes record */
+#define	MSG_TRUNC	0x10		/* data discarded before delivery */
+#define	MSG_CTRUNC	0x20		/* control data lost before delivery */
+#define	MSG_WAITALL	0x40		/* wait for full request or error */
+#define	MSG_DONTWAIT	0x80		/* this message should be nonblocking */
+#define	MSG_BCAST	0x100		/* this message was rcvd using link-level brdcst */
+#define	MSG_MCAST	0x200		/* this message was rcvd using link-level mcast */
+
+/*
+ * Types of socket shutdown(2).
+ */
+#define	SHUT_RD		0		/* Disallow further receives. */
+#define	SHUT_WR		1		/* Disallow further sends. */
+#define	SHUT_RDWR	2		/* Disallow further sends/receives. */
+
+struct iovec {
+	void	*iov_base;	/* Base address. */
+	size_t	 iov_len;	/* Length. */
+};
+
+struct msghdr {
+	void		*msg_name;	/* optional address */
+	socklen_t	msg_namelen;	/* size of address */
+	struct iovec	*msg_iov;	/* scatter/gather array */
+	int		msg_iovlen;	/* # elements in msg_iov */
+	void		*msg_control;	/* ancillary data, see below */
+	socklen_t	msg_controllen;	/* ancillary data buffer len */
+	int		msg_flags;	/* flags on received message */
+};
+
+/* BSD-compatible socket API. */
+int	accept(int, struct sockaddr * __restrict, socklen_t * __restrict);
+int	bind(int, const struct sockaddr *, socklen_t);
+int	connect(int, const struct sockaddr *, socklen_t);
+int	getpeername(int, struct sockaddr * __restrict, socklen_t * __restrict);
+int	getsockname(int, struct sockaddr * __restrict, socklen_t * __restrict);
+int	getsockopt(int, int, int, void * __restrict, socklen_t * __restrict);
+int	listen(int, int);
+ssize_t	recv(int, void *, size_t, int);
+ssize_t	recvfrom(int, void * __restrict, size_t, int,
+	    struct sockaddr * __restrict, socklen_t * __restrict);
+ssize_t recvmsg(int s, struct msghdr *msg, int flags);
+ssize_t	send(int, const void *, size_t, int);
+ssize_t	sendto(int, const void *,
+	    size_t, int, const struct sockaddr *, socklen_t);
+ssize_t sendmsg(int s, const struct msghdr *msg, int flags);
+int	setsockopt(int, int, int, const void *, socklen_t);
+int	shutdown(int, int);
+int	socket(int, int, int);
+
+/* sceNetInet socket API. */
+int	sceNetInetAccept(int s, struct sockaddr *addr, socklen_t *addrlen);
+int	sceNetInetBind(int s, const struct sockaddr *my_addr, socklen_t addrlen);
+int	sceNetInetConnect(int s, const struct sockaddr *serv_addr, socklen_t addrlen);
+int	sceNetInetGetsockopt(int s, int level, int optname, void *optval, socklen_t *optlen);
+int	sceNetInetListen(int s, int backlog);
+ssize_t	sceNetInetRecv(int s, void *buf, size_t len, int flags);
+ssize_t	sceNetInetRecvfrom(int s, void *buf, size_t flags, int, struct sockaddr *from, socklen_t *fromlen);
+ssize_t sceNetInetRecvmsg(int s, struct msghdr *msg, int flags);
+ssize_t	sceNetInetSend(int s, const void *buf, size_t len, int flags);
+ssize_t	sceNetInetSendto(int s, const void *buf, size_t len, int flags, const struct sockaddr *to, socklen_t tolen);
+ssize_t sceNetInetSendmsg(int s, const struct msghdr *msg, int flags);
+int	sceNetInetSetsockopt(int s, int level, int optname, const void *optval, socklen_t optlen);
+int	sceNetInetShutdown(int s, int how);
+int	sceNetInetSocket(int domain, int type, int protocol);
+int sceNetInetClose(int s);
+int sceNetInetGetErrno(void);
+int sceNetInetGetsockname(int s, struct sockaddr *name, socklen_t *namelen);
+int sceNetInetGetpeername(int s, struct sockaddr *name, socklen_t *namelen);
+
+#ifdef __cplusplus
+}
+#endif
+
+#endif /* !_SYS_SOCKET_H_ */
