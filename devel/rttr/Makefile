PORTNAME=	rttr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.6-16
PORTREVISION=	2
DISTVERSIONSUFFIX=	-gb3a131c
CATEGORIES=	devel

PATCH_SITES=	https://github.com/rttrorg/rttr/commit/
PATCHFILES=	992df30caa14fe6bfcd2c38213314622e1e02aae.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Run Time Type Reflection

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/rapidjson/rapidjson.h:devel/rapidjson \
		${LOCALBASE}/include/chaiscript/chaiscript.hpp:lang/chaiscript

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	rttrorg

CMAKE_OFF=	BUILD_DOCUMENTATION \
		BUILD_UNIT_TESTS \
		BUILD_EXAMPLES

PORTSCOUT=	limit:^0\.

post-extract:
	${RM} -r ${WRKSRC}/3rd_party/rapidjson-1.1.0/
	${RM} -r ${WRKSRC}/3rd_party/chaiscript-devel/
	${RM} -r ${WRKSRC}/3rd_party/chaiscript-6.1.0/

.include <bsd.port.mk>
