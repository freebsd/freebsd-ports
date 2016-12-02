# $FreeBSD$

PORTNAME=	ivykis
PORTVERSION=	0.39
DISTVERSIONPREFIX=v
CATEGORIES=	devel

MAINTAINER=	algernon@madhouse-project.org
COMMENT=	Asynchronous I/O readiness notification library

LICENSE=	LGPL21

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	buytenh

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libivykis.so.0.4.2

.include <bsd.port.mk>
