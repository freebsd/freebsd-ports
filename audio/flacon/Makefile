PORTNAME=	flacon
PORTVERSION=	11.3.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical audio file extractor and encoder
WWW=		https://flacon.github.io/

LICENSE=	LGPL21+

# XXX: yaml-cpp is needed for tests/flacon_test program only
BUILD_DEPENDS=	${LOCALBASE}/include/yaml-cpp/yaml.h:devel/yaml-cpp
LIB_DEPENDS=	libtag.so:audio/taglib \
		libuchardet.so:textproc/uchardet
TEST_DEPENDS=	alacenc:audio/alacenc \
		faac:audio/faac flac:audio/flac \
		lame:audio/lame mac:audio/mac \
		mediainfo:multimedia/mediainfo \
		oggenc:audio/vorbis-tools \
		opusenc:audio/opus-tools sox:audio/sox \
		ttaenc:audio/tta wavpack:audio/wavpack

USES=		cmake compiler:c++11-lang desktop-file-utils pkgconfig qt:5
USE_GITHUB=	yes
USE_QT=		buildtools:build concurrent:build qmake:build testlib:build \
		linguisttools:build core gui network widgets
CMAKE_ARGS=	-DBUILD_TESTS:BOOL=YES

do-test:
	@cd ${TEST_WRKSRC} && LC_ALL=C.UTF-8 ctest -C ${CMAKE_BUILD_TYPE} \
		${_MAKE_JOBS}
	@${CAT} ${TEST_WRKSRC}/Testing/Temporary/LastTest.log

.include <bsd.port.mk>
