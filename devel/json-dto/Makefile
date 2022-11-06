PORTNAME=	json-dto
DISTVERSIONPREFIX=	v.
DISTVERSION=	0.3.1
CATEGORIES=	devel textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only library for converting data between JSON and C++ structs
WWW=		https://github.com/Stiffstream/json_dto

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	catch>0:devel/catch \
		rapidjson>0:devel/rapidjson
RUN_DEPENDS=	rapidjson>0:devel/rapidjson

USES=		cmake:testing compiler:c++14-lang localbase

USE_GITHUB=	yes
GH_ACCOUNT=	Stiffstream
GH_PROJECT=	json_dto

WRKSRC_SUBDIR=	dev

CMAKE_OFF=	JSON_DTO_TEST JSON_DTO_SAMPLE
CMAKE_TESTING_ON=	JSON_DTO_TEST

NO_ARCH=	yes

PLIST_FILES=	include/json_dto/pub.hpp \
		include/json_dto/validators.hpp \
		lib/cmake/json-dto/json-dto-config-version.cmake \
		lib/cmake/json-dto/json-dto-config.cmake \
		lib/cmake/json-dto/json-dto-targets.cmake

.include <bsd.port.mk>
