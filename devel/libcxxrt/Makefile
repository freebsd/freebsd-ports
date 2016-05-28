# $FreeBSD$

PORTNAME=	libcxxrt
PORTVERSION=	20131225
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	mokhi64@gmail.com
COMMENT=	Implementation of the Code Sourcery C++ ABI

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	pathscale
GH_TAGNAME=	2f150a6

USES=		cmake compiler:c++11-lang
CXXFLAGS+=	-nostdlib

do-install:
	${INSTALL_LIB} ${WRKSRC}/lib/libcxxrt.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libcxxrt.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/cxxrt
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include/cxxrt

.include <bsd.port.mk>
