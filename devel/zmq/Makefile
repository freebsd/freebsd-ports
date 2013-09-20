# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	zmq
PORTVERSION=	2.2.0
CATEGORIES=	devel net
MASTER_SITES=	http://download.zeromq.org/
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	Open source message queue optimised for performance

GNU_CONFIGURE=	yes
USES=	pathfix
USE_LDCONFIG=	yes

CONFLICTS=	zmq-devel-[0-9]*

MAN3=		zmq_bind.3 \
		zmq_close.3 \
		zmq_connect.3 \
		zmq_device.3 \
		zmq_errno.3 \
		zmq_getsockopt.3 \
		zmq_init.3 \
		zmq_msg_close.3 \
		zmq_msg_copy.3 \
		zmq_msg_data.3 \
		zmq_msg_init.3 \
		zmq_msg_init_data.3 \
		zmq_msg_init_size.3 \
		zmq_msg_move.3 \
		zmq_msg_size.3 \
		zmq_poll.3 \
		zmq_recv.3 \
		zmq_send.3 \
		zmq_setsockopt.3 \
		zmq_socket.3 \
		zmq_strerror.3 \
		zmq_term.3 \
		zmq_version.3
MAN7=		zmq.7 \
		zmq_cpp.7 \
		zmq_epgm.7 \
		zmq_inproc.7 \
		zmq_ipc.7 \
		zmq_pgm.7 \
		zmq_tcp.7

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e '9s|$$| -pthread|' ${WRKSRC}/src/libzmq.pc.in

.include <bsd.port.mk>
