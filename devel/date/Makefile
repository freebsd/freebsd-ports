PORTNAME=	date
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.3
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Date and time library based on the C++11 (and beyond) <chrono> header
WWW=		https://github.com/HowardHinnant/date

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcurl.so:ftp/curl
TEST_DEPENDS=	bash:shells/bash

USES=		cmake:testing compiler:c++17-lang shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	HowardHinnant
GH_PROJECT=	date

SHEBANG_FILES=	test_fail.sh

CMAKE_OFF=	COMPILE_WITH_C_LOCALE \
		DISABLE_STRING_VIEW \
		MANUAL_TZ_DB \
		USE_SYSTEM_TZ_DB \
		USE_TZ_DB_IN_DOT
CMAKE_ON=	BUILD_SHARED_LIBS \
		BUILD_TZ_LIB \
		ENABLE_DATE_INSTALL
CMAKE_TESTING_ON=	ENABLE_DATE_TESTING

# tests fail to run because executables aren't built, see https://github.com/HowardHinnant/date/issues/855

.include <bsd.port.mk>
