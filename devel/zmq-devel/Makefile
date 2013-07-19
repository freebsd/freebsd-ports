# $FreeBSD$

PORTNAME=	zmq
PORTVERSION=	3.2.3
CATEGORIES=	devel net
MASTER_SITES=	http://download.zeromq.org/
PKGNAMESUFFIX=	-devel
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source message queue optimised for performance

MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USES=	pathfix
USE_LDCONFIG=	yes

CONFLICTS=	zmq-[0-9]*

MAN7=	\
	zmq_pgm.7 \
	zmq_ipc.7 \
	zmq_epgm.7 \
	zmq_tcp.7 \
	zmq.7 \
	zmq_inproc.7

MAN3=	\
	zmq_bind.3 \
	zmq_close.3 \
	zmq_connect.3 \
	zmq_ctx_destroy.3 \
	zmq_ctx_get.3 \
	zmq_ctx_new.3 \
	zmq_ctx_set.3 \
	zmq_disconnect.3 \
	zmq_errno.3 \
	zmq_getsockopt.3 \
	zmq_init.3 \
	zmq_msg_close.3 \
	zmq_msg_copy.3 \
	zmq_msg_data.3 \
	zmq_msg_get.3 \
	zmq_msg_init.3 \
	zmq_msg_init_data.3 \
	zmq_msg_init_size.3 \
	zmq_msg_more.3 \
	zmq_msg_move.3 \
	zmq_msg_recv.3 \
	zmq_msg_send.3 \
	zmq_msg_set.3 \
	zmq_msg_size.3 \
	zmq_poll.3 \
	zmq_proxy.3 \
	zmq_recv.3 \
	zmq_recvmsg.3 \
	zmq_send.3 \
	zmq_sendmsg.3 \
	zmq_setsockopt.3 \
	zmq_socket.3 \
	zmq_socket_monitor.3 \
	zmq_strerror.3 \
	zmq_term.3 \
	zmq_unbind.3 \
	zmq_version.3

regression-test:
	cd ${WRKSRC} && ${MAKE}	check

.include <bsd.port.pre.mk>

.if defined(CC) && ${CC:T:M*clang*} == "clang" || ${OSVERSION} >= 1000024
CXXFLAGS+=	-Wno-mismatched-tags
.endif

.include <bsd.port.post.mk>
