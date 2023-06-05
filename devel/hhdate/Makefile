PORTNAME=	hhdate
PORTVERSION=	3.0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Date and time library based on the C++11 (and beyond) <chrono> header
WWW=		https://github.com/HowardHinnant/date

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake compiler:c++17-lang

CMAKE_OFF=	COMPILE_WITH_C_LOCALE DISABLE_STRING_VIEW ENABLE_DATE_TESTING MANUAL_TZ_DB USE_SYSTEM_TZ_DB USE_TZ_DB_IN_DOT
CMAKE_ON=	BUILD_SHARED_LIBS BUILD_TZ_LIB
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	HowardHinnant
GH_PROJECT=	date

.include <bsd.port.mk>
