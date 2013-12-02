# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	zmq
PORTVERSION=	3.2.3
CATEGORIES=	devel net
MASTER_SITES=	http://download.zeromq.org/
PKGNAMEPREFIX=	ntopng-
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	NTOPNG specific ZMQ library

LICENSE=	LGPL3

CONFIGURE_ARGS=	--disable-silent-rules --without-documentation
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_GCC=	any
USE_LDCONFIG=	yes
USES=		pathfix

CONFLICTS=	zmq-[0-9]*

post-patch:
	@${REINPLACE_CMD} 's/tests//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
