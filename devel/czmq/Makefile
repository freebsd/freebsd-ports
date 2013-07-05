# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	czmq
PORTVERSION=	1.4.1
CATEGORIES=	devel net
MASTER_SITES=	http://download.zeromq.org/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	High-level C Binding for zmq

LICENSE=	LGPL3

LIB_DEPENDS=	zmq:${PORTSDIR}/devel/zmq

USES=	pathfix gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_czmq_have_asciidoc=no
CONFIGURE_ARGS=	--with-libzmq=${LOCALBASE}
USE_LDCONFIG=	yes

MAN3= 		zbeacon.3 \
		zclock.3 \
		zctx.3 \
		zfile.3 \
		zframe.3 \
		zhash.3 \
		zlist.3 \
		zloop.3 \
		zmsg.3 \
		zmutex.3 \
		zsocket.3 \
		zsockopt.3 \
		zstr.3 \
		zsys.3 \
		zthread.3

MAN7=		czmq.7

.include <bsd.port.mk>
