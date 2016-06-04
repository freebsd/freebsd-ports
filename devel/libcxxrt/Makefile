# $FreeBSD$

PORTNAME=	libcxxrt
PORTVERSION=	20160529
CATEGORIES=	devel

MAINTAINER=	mokhi64@gmail.com
COMMENT=	Implementation of the Code Sourcery C++ ABI

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	pathscale
GH_TAGNAME=	516a65c

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes
CXXFLAGS+=	-nostdlib

do-install:
	${INSTALL_LIB} ${WRKSRC}/lib/libcxxrt.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libcxxrt.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/cxxrt
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include/cxxrt

.include <bsd.port.mk>
