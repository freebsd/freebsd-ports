# Created by: Wen Heping <wenheping@gmail.com>

PORTNAME=	swe
PORTVERSION=	2.10.02
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	astro devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High Precision Ephemeris Developed By Astrodienst

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/agpl-3.0.txt

USES=		gmake
USE_GITHUB=	yes

GH_ACCOUNT=	aloistr
GH_PROJECT=	swisseph

ALL_TARGET=	#

post-patch:
	@${REINPLACE_CMD} 's|-ldl||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libswe.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/swe
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/swe

.include <bsd.port.mk>
