PORTNAME=	gpds
DISTVERSION=	1.8.4
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	General purpose data serializer library written in modern C++
WWW=		https://github.com/simulton/gpds

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	tinyxml2>10:textproc/tinyxml2
LIB_DEPENDS=	libtinyxml2.so:textproc/tinyxml2
RUN_DEPENDS=	tinyxml2>10:textproc/tinyxml2

USES=		cmake compiler:c++20-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	simulton

CMAKE_ON=	GPDS_BUILD_STATIC GPDS_BUILD_SHARED GPDS_DEPENDENCY_TINYXML2_PKGCONFIG
CMAKE_OFF=	GPDS_BUILD_EXAMPLES GPDS_BUILD_TESTS

PLIST_SUB=	SOVERSION="${DISTVERSION}"

.include <bsd.port.mk>
