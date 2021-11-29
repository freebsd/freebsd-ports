# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	flacon
PORTVERSION=	8.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical audio file extractor and encoder

LICENSE=	LGPL21+

LIB_DEPENDS=	libtag.so:audio/taglib \
		libuchardet.so:textproc/uchardet
TEST_DEPENDS=	mac:audio/mac ttaenc:audio/tta

USES=		cmake compiler:c++11-lang desktop-file-utils pkgconfig qt:5
USE_GITHUB=	yes
USE_QT=		buildtools_build concurrent_build qmake_build testlib_build \
		linguisttools_build core gui network widgets
CMAKE_ARGS=	-DBUILD_TESTS:BOOL=YES

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
