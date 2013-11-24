# $FreeBSD$

PORTNAME=	zmq
PORTVERSION=	3.2.4
CATEGORIES=	devel net
MASTER_SITES=	http://download.zeromq.org/
PKGNAMESUFFIX=	-devel
DISTNAME=	zeromq-${DISTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Lightweight messaging kernel

USES=		pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules

CONFLICTS=	zmq-[0-9]*

regression-test:
	cd ${WRKSRC} && ${MAKE}	check

.include <bsd.port.mk>
