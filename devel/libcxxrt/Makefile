# $FreeBSD$

PORTNAME=	libcxxrt
PORTVERSION=	20131225
CATEGORIES=	devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Implementation of the Code Sourcery C++ ABI

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	pathscale
GH_COMMIT=	2f150a6
GH_TAGNAME=	${GH_COMMIT}

USES=		cmake

do-install:
	${INSTALL_LIB} ${WRKSRC}/lib/libcxxrt.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/libcxxrt.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/cxxrt
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include/cxxrt

.include <bsd.port.mk>
