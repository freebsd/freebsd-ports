PORTNAME=	glaze
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.2
CATEGORIES=	devel textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, in memory, JSON and interface library for modern C++
WWW=		https://github.com/stephenberry/glaze

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_15=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276265

BUILD_DEPENDS=	${LOCALBASE}/include/asio.hpp:net/asio
TEST_DEPENDS=	ut>0:devel/ut

USES=		cmake:testing compiler:c++11-lang eigen:3 localbase

USE_GITHUB=	yes
GH_ACCOUNT=	stephenberry

CMAKE_OFF=	BUILD_TESTING
CMAKE_ARGS=	-DFETCHCONTENT_TRY_FIND_PACKAGE_MODE=ALWAYS
CMAKE_TESTING_ARGS=	-DFREEBSD_STAGEDIR_PREFIX=${STAGEDIR}${DATADIR}

LDFLAGS+=	-pthread

NO_ARCH=	yes

.include <bsd.port.mk>
