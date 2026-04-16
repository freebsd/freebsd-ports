PORTNAME=	swe
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.3
DISTVERSIONSUFFIX=	final
PORTEPOCH=	1
CATEGORIES=	astro devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High Precision Ephemeris Developed By Astrodienst
WWW=		https://www.astro.com/swisseph/

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
