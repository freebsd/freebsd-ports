# $FreeBSD$

PORTNAME=	nanort
DISTVERSIONPREFIX=	v
DISTVERSION=	g20201207
CATEGORIES=	graphics devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ single header modern ray tracing kernel

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	lighttransport
GH_TAGNAME=	b1feea8

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/nanort.h

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} nanort.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
