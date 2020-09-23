# $FreeBSD$

PORTNAME=	pystring
PORTVERSION=	1.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Collection of C++ functions which match python's string class

USES=		libtool:build
USE_GITHUB=	yes
GH_ACCOUNT=	imageworks
MAKE_ARGS=	CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS}" \
		LIBDIR="${STAGEDIR}${PREFIX}/lib"
USE_LDCONFIG=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/pystring
	${INSTALL_DATA} ${WRKSRC}/pystring.h ${STAGEDIR}${PREFIX}/include/pystring
	${INSTALL_DATA} ${WRKSRC}/unittest.h ${STAGEDIR}${PREFIX}/include/pystring

.include <bsd.port.mk>
