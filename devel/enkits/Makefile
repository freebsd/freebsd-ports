PORTNAME=	enkits
DISTVERSION=	g20260603
CATEGORIES=	devel

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Lightweight C and C++ task scheduler for parallel programs
WWW=		https://github.com/dougbinks/enkiTS

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	dougbinks
GH_PROJECT=	enkiTS
GH_TAGNAME=	0289cf6ffce86697e1f46cb4eeca1c946bffec71

CMAKE_OFF=	ENKITS_BUILD_EXAMPLES
CMAKE_ON=	ENKITS_BUILD_C_INTERFACE \
		ENKITS_INSTALL \
		ENKITS_BUILD_SHARED

PLIST_FILES=	include/enkiTS/LockLessMultiReadPipe.h \
		include/enkiTS/TaskScheduler.h \
		include/enkiTS/TaskScheduler_c.h \
		lib/cmake/enkiTS/enkiTSConfig-${CMAKE_BUILD_TYPE:tl}.cmake \
		lib/cmake/enkiTS/enkiTSConfig.cmake \
		lib/libenkiTS.so \
		lib/libenkiTS.so.1 \
		lib/libenkiTS.so.1.11

.include <bsd.port.mk>
