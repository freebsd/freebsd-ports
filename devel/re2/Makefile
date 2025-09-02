PORTNAME=	re2
PORTVERSION=	20250805
CATEGORIES=	devel
MASTER_SITES=	https://github.com/google/re2/releases/download/${PORTVERSION:C|(....)(..)(..)|\1-\2-\3|}/
DISTNAME=	re2-${PORTVERSION:C|(....)(..)(..)|\1-\2-\3|}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast C++ regex library
WWW=		https://github.com/google/re2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	abseil>=20240116.2:devel/abseil
LIB_DEPENDS=	libabsl_base.so:devel/abseil

USES=		compiler:c++17-lang gmake localbase:ldflags pathfix pkgconfig

MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" SED_INPLACE="${SED} -i ''" prefix=${PREFIX}
PATHFIX_MAKEFILEIN=	Makefile
TEST_TARGET=	test
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libre2.so

.include <bsd.port.mk>
