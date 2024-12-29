PORTNAME=	sfizz
DISTVERSION=	1.2.3
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SFZ parser and synth C++ library & LV2/VST3 plugins
WWW=		https://sfz.tools/sfizz/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libabsl_hash.so:devel/abseil
RUN_DEPENDS=	zenity:x11/zenity

USES=		cmake compiler:c++17-lang localbase:ldflags pkgconfig qt:5
USE_QT=		buildtools:build qmake:build widgets

USE_GITHUB=	yes
GH_ACCOUNT=	sfztools
GH_TUPLE=	mackron:dr_libs:e4a7765e598e9e54dc0f520b7e4416359bee80cc:mackron_dr_libs/external/st_audiofile/thirdparty/dr_libs \
		sfztools:libaiff:78864a4a2e769e426be8cfd78ae7f5f72e236c33:sfztools_libaiff/external/st_audiofile/thirdparty/libaiff \
		gulrak:filesystem:8a2edd6d92ed820521d42c94d179462bf06b5ed3:gulrak_filesystem/external/filesystem \
		simd-everywhere:simde:2bf459d4ed6d7ed6b9f31bd9e07c91bace5009e0:simd_everywhere_simde/external/simde \
		dbry:WavPack:07ffb331d23c16e2d2979370441f63ea722760bc:dbry_WavPack/external/st_audiofile/thirdparty/wavpack \
		doctest:doctest:86892fc480f80fb57d9a3926cb506c0e974489d8:doctest_doctest/external/invoke.hpp/vendors/doctest \
		nemequ:munit:da8f73412998e4f1adf1100dc187533a51af77fd:nemequ_munit/external/simde/test/munit \
		dr-soft:miniaudio:d1a166c83ab445b1c14bc83d37c84e18d172e5f5:dr_soft_miniaudio/external/st_audiofile/thirdparty/dr_libs/tests/external/miniaudio

USE_LDCONFIG=	yes

CMAKE_ON=	SFIZZ_USE_SYSTEM_ABSEIL
CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17

OPTIONS_DEFINE=		JACK
OPTIONS_DEFAULT=	JACK
OPTIONS_SUB=		yes

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	SFIZZ_JACK

post-patch:
	# fix conflict of CACHE_LINE_SIZE with system-defined macro
	@${REINPLACE_CMD} \
		-e 's|CACHE_LINE_SIZE|CACHE_LINE_SIZEx|' \
		${WRKSRC}/external/atomic_queue/include/atomic_queue/atomic_queue.h \
		${WRKSRC}/external/atomic_queue/include/atomic_queue/defs.h
	@${REINPLACE_CMD} \
		-E -e 's/(template do_(push|pop)_any)/\1<>/' \
		${WRKSRC}/external/atomic_queue/include/atomic_queue/atomic_queue.h

.include <bsd.port.mk>
