# $FreeBSD$

PORTNAME=	zmq
PORTVERSION=	3.2.4
CATEGORIES=	devel net
MASTER_SITES=	http://download.zeromq.org/
PKGNAMESUFFIX=	-devel
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source message queue optimised for performance

USES=		pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules
USE_LDCONFIG=	yes

CONFLICTS=	zmq-[0-9]*

regression-test:
	cd ${WRKSRC} && ${MAKE}	check

.include <bsd.port.mk>
