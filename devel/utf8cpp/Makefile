PORTNAME=	utf8cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.3
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, portable, lightweight library for handling UTF-8 strings
WWW=		https://github.com/nemtrif/utfcpp

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	nemtrif
GH_PROJECT=	utfcpp

NO_ARCH=	yes

PLIST_FILES=	include/utf8cpp/utf8.h \
		include/utf8cpp/utf8/checked.h \
		include/utf8cpp/utf8/core.h \
		include/utf8cpp/utf8/cpp11.h \
		include/utf8cpp/utf8/cpp17.h \
		include/utf8cpp/utf8/unchecked.h \
		lib/cmake/utf8cpp/utf8cppConfig.cmake \
		lib/cmake/utf8cpp/utf8cppConfigVersion.cmake \
		lib/cmake/utf8cpp/utf8cppTargets.cmake

.include <bsd.port.mk>
