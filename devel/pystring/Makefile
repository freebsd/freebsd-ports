PORTNAME=	pystring
PORTVERSION=	1.1.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Collection of C++ functions which match python's string class
WWW=		https://github.com/imageworks/pystring

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool:build
USE_GITHUB=	yes
GH_ACCOUNT=	imageworks
USE_LDCONFIG=	yes

MAKE_ARGS=	CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS}" \
		LIBDIR="${STAGEDIR}${PREFIX}/lib"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/pystring
	${INSTALL_DATA} ${WRKSRC}/pystring.h ${STAGEDIR}${PREFIX}/include/pystring
	${INSTALL_DATA} ${WRKSRC}/unittest.h ${STAGEDIR}${PREFIX}/include/pystring

.include <bsd.port.mk>
