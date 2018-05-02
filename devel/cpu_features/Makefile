# $FreeBSD$

PORTNAME=	cpu_features
PORTVERSION=	0.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Cross platform C99 library to get cpu features at runtime

LICENSE=	APACHE20

USES=	cmake
USE_GITHUB=	yes
GH_ACCOUNT=	google

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/list_cpu_features ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libcpu_features.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/internal
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/internal/*.h ${STAGEDIR}${PREFIX}/include/internal

.include <bsd.port.mk>
