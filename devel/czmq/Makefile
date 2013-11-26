# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	czmq
PORTVERSION=	1.4.1
CATEGORIES=	devel net
MASTER_SITES=	http://download.zeromq.org/

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	High-level C Binding for zmq

LICENSE=	LGPL3

LIB_DEPENDS=	libzmq.so:${PORTSDIR}/devel/zmq

USES=	pathfix gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_czmq_have_asciidoc=no
CONFIGURE_ARGS=	--with-libzmq=${LOCALBASE}
USE_LDCONFIG=	yes

.include <bsd.port.mk>
