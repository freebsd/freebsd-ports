PORTNAME=	flacon
PORTVERSION=	12.0.0
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

USES=		cmake compiler:c++17-lang desktop-file-utils iconv \
		pkgconfig qt:5
USE_GITHUB=	yes
USE_QT=		buildtools:build concurrent:build qmake:build testlib:build \
		linguisttools:build core gui network widgets
CMAKE_ARGS=	-DBUILD_TESTS:BOOL=YES

post-patch:
# Catch up with newish MediaInfo(Lib) tag names so the tests can pass:
# Part -> Part_Position in tests 18.{1,5,6}
.for n f in 1 FLAC 5 OGG 6 OPUS
	@${REINPLACE_CMD} -E 's,^Part {9},Part_Position,' \
		${WRKSRC}/tests/data/testConvert/18.$n\ tags\ $f/spec.ini
.endfor
# Cover_Type "Cover (front)" changed to "Cover" (25.04 -> 25.05)
	@${REINPLACE_CMD} -e '/^Cover_Type/s,Cover (front),Cover,' \
		${WRKSRC}/tests/data/testConvert/18.1\ tags\ FLAC/spec.ini

do-test:
	@ctest --test-dir ${TEST_WRKSRC} -C ${CMAKE_BUILD_TYPE} \
		${_MAKE_JOBS} || { rc=$$?; ${CAT} \
		${TEST_WRKSRC}/Testing/Temporary/LastTest.log; \
		return $$rc; }

.include <bsd.port.mk>
