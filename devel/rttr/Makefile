PORTNAME=	rttr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.6-16
DISTVERSIONSUFFIX=	-gb3a131c
PORTREVISION=	3
CATEGORIES=	devel

PATCH_SITES=	https://github.com/rttrorg/rttr/commit/
PATCHFILES=	992df30caa14fe6bfcd2c38213314622e1e02aae.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Run Time Type Reflection
WWW=		https://github.com/rttrorg/rttr

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/rapidjson/rapidjson.h:devel/rapidjson \
		${LOCALBASE}/include/chaiscript/chaiscript.hpp:lang/chaiscript

USES=		cmake compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rttrorg

CMAKE_OFF=	BUILD_DOCUMENTATION \
		BUILD_UNIT_TESTS \
		BUILD_EXAMPLES

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/3rd_party/chaiscript-* \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/3rd_party/rapidjson-* \
			--no-same-owner --no-same-permissions

PORTSCOUT=	limit:^0\.

.include <bsd.port.mk>
