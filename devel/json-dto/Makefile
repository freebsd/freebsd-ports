PORTNAME=	json-dto
DISTVERSION=	0.3.1
CATEGORIES=	devel textproc
MASTER_SITES=	https://github.com/Stiffstream/json_dto/releases/download/v.${DISTVERSION}/
DISTNAME=	json_dto-${DISTVERSION}-full

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only library for converting data between JSON and C++ structs
WWW=		https://github.com/Stiffstream/json_dto

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	catch>0:devel/catch \
		rapidjson>0:devel/rapidjson
RUN_DEPENDS=	rapidjson>0:devel/rapidjson

USES=		cmake:testing compiler:c++14-lang localbase tar:bz2

WRKSRC=		${WRKDIR}/json_dto-${DISTVERSION}
WRKSRC_SUBDIR=	dev

CMAKE_OFF=	JSON_DTO_TEST JSON_DTO_SAMPLE
CMAKE_TESTING_ON=	JSON_DTO_TEST

NO_ARCH=	yes

PLIST_FILES=	include/json_dto/pub.hpp \
		include/json_dto/validators.hpp \
		lib/cmake/json-dto/json-dto-config-version.cmake \
		lib/cmake/json-dto/json-dto-config.cmake \
		lib/cmake/json-dto/json-dto-targets.cmake

post-extract:
		${RM} -rf ${WRKSRC}/catch2
		${RM} -rf ${WRKSRC}/rapidjson
		${RM} -rf ${WRKSRC}/rapidjson_mxxru

.include <bsd.port.mk>
