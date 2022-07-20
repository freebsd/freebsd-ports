PORTNAME=	flacon
PORTVERSION=	9.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical audio file extractor and encoder

LICENSE=	LGPL21+

LIB_DEPENDS=	libtag.so:audio/taglib \
		libuchardet.so:textproc/uchardet
TEST_DEPENDS=	flac:audio/flac mac:audio/mac mediainfo:multimedia/mediainfo \
		ttaenc:audio/tta wavpack:audio/wavpack

USES=		cmake compiler:c++11-lang desktop-file-utils pkgconfig qt:5
USE_GITHUB=	yes
USE_QT=		buildtools_build concurrent_build qmake_build testlib_build \
		linguisttools_build core gui network widgets
CMAKE_ARGS=	-DBUILD_TESTS:BOOL=YES

do-test:
	@cd ${TEST_WRKSRC} && LC_ALL=C.UTF-8 ctest -C ${CMAKE_BUILD_TYPE} \
		${_MAKE_JOBS}

.include <bsd.port.mk>
