PORTNAME=	mame
DISTVERSION=	0.255
CATEGORIES=	emulators games

MAINTAINER=	agh@riseup.net
COMMENT=	MAME: a multi-purpose emulation framework
WWW=		https://mamedev.org/

LICENSE=	BSD2CLAUSE BSD3CLAUSE CC0-1.0 GPLv2 LGPL21 MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/docs/legal/BSD-2-Clause
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/docs/legal/BSD-3-Clause
LICENSE_FILE_CC0-1.0=	${WRKSRC}/docs/legal/CC0
LICENSE_FILE_GPLv2=	${WRKSRC}/docs/legal/GPL-2.0
LICENSE_FILE_LGPL21=	${WRKSRC}/docs/legal/LGPL-2.1
LICENSE_FILE_MIT=	${WRKSRC}/docs/legal/MIT
LICENSE_FILE_ZLIB=	${WRKSRC}/docs/legal/Zlib
LICENSE_FILE=	${WRKSRC}/docs/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386 powerpc powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	not yet ported to any architecture other than armv7, arm64, x86, and powerpc*

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinxcontrib-svg2pdfconverter>0:textproc/py-sphinxcontrib-svg2pdfconverter@${PY_FLAVOR} \
		glm>0:math/glm \
		rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libFLAC.so:audio/flac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libportmidi.so:audio/portmidi \
		libpugixml.so:textproc/pugixml \
		libutf8proc.so:textproc/utf8proc \
		libuv.so:devel/libuv
RUN_DEPENDS=	liberation-fonts-ttf>=0:x11-fonts/liberation-fonts-ttf

USES=		compiler:c++17-lang gl gmake jpeg localbase lua:54 pkgconfig \
		python:3.9,build sdl shebangfix sqlite:3 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	mamedev
GH_TAGNAME=	mame${DISTVERSION:S/.//}
USE_GL=		gl
USE_SDL=	sdl2 ttf2
USE_XORG=	x11 xext xi xinerama xrender

MAKEFILE=	makefile
MAKE_ARGS=	TARGETOS=freebsd \
		VERBOSE="1"
MAKE_ENV=	LDOPTS="${LDFLAGS}" \
		NO_USE_PORTAUDIO=1 \
		NO_USE_PULSEAUDIO=1 \
		NOWERROR=1 \
		OPT_FLAGS="${CXXFLAGS}" \
		PRECOMPILE=0 \
		PYTHON_EXECUTABLE="${PYTHON_CMD}" \
		USE_PCAP=1 \
		USE_SYSTEM_LIB_EXPAT=1 \
		USE_SYSTEM_LIB_FLAC=1 \
		USE_SYSTEM_LIB_GLM=1 \
		USE_SYSTEM_LIB_JPEG=1 \
		USE_SYSTEM_LIB_PORTMIDI=1 \
		USE_SYSTEM_LIB_PUGIXML=1 \
		USE_SYSTEM_LIB_RAPIDJSON=1 \
		USE_SYSTEM_LIB_SQLITE3=1 \
		USE_SYSTEM_LIB_UTF8PROC=1 \
		USE_SYSTEM_LIB_UV=1 \
		USE_SYSTEM_LIB_ZLIB=1 \
		USE_TAPTUN=1

SUB_FILES=	pkg-message mame.ini plugin.ini ui.ini

PORTDOCS=	html/*

OPTIONS_DEFINE=	DEBUG DOCS QTDEBUGGER TOOLS
OPTIONS_SUB=	yes

DEBUG_DESC=		Build with debug profiling and symbols
DOCS_DESC=		Install extensive online MAME documentation
QTDEBUGGER_DESC=	Install Qt interactive low-level machine debugger
TOOLS_DESC=		Install tools for machine archiving and development

DEBUG_MAKE_ENV=			DEBUG=1 \
				OPTIMIZE=0 \
				PROFILER=1 \
				SYMBOLS=1
DEBUG_MAKE_ENV_OFF=		OPTIMIZE=2 \
				STRIP_SYMBOLS=1
# Attempt to avoid address space exhaustion during linking, specifically
# on armv7, and possibly other architectures:
DEBUG_LDFLAGS_OFF=		-s
QTDEBUGGER_USES=		qt:5
QTDEBUGGER_USE=			QT=core,gui,widgets,buildtools:build,qmake:build
QTDEBUGGER_MAKE_ENV=		USE_QTDEBUG=1
QTDEBUGGER_MAKE_ENV_OFF=	USE_QTDEBUG=0
TOOLS_MAKE_ENV=			TOOLS=1
TOOLS_MAKE_ENV_OFF=		TOOLS=0

_GENIE=		${WRKSRC}/3rdparty/genie

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	yes
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1400000
.if ${ARCH:Mpowerpc*}
USES+=		llvm:min=16,build
.else
USES+=		llvm:15,build
.endif
MAKE_ENV+=	OVERRIDE_AR="llvm-ar${LLVM_VERSION}" \
		OVERRIDE_CC="clang${LLVM_VERSION}" \
		OVERRIDE_CXX="clang++${LLVM_VERSION}" \
		OVERRIDE_LD="lld${LLVM_VERSION}"
.else
MAKE_ENV+=	OVERRIDE_AR="${AR}" \
		OVERRIDE_CC="${CC}" \
		OVERRIDE_CXX="${CXX}" \
		OVERRIDE_LD="${LD}"
.endif

.if ${ARCH:Maarch64} || ${ARCH:Mamd64} || ${ARCH:Mpowerpc64*}
MAKE_ARGS+=	PTR64=1
.endif

post-extract:
	@${MV} ${WRKSRC}/src/lib/util/png.h \
		${WRKSRC}/src/lib/util/localpng.h

post-patch:
# Prefer some system headers over bundled.
	@${RM} ${WRKSRC}/3rdparty/bx/include/compat/freebsd/dirent.h
	@${RM} ${WRKSRC}/3rdparty/bx/include/compat/freebsd/signal.h
# Accommodate GENie conception of BSD.
	@${MV} ${_GENIE}/build/gmake.freebsd \
		${_GENIE}/build/gmake.bsd
# Patch build to use bundled PNG.
	@${GREP} -rl '"png.h"' ${WRKSRC}/src | \
		${XARGS} ${REINPLACE_CMD} -e 's|"png.h"|"localpng.h"|'
	@${REINPLACE_CMD} -e 's|"util/png.h"|"util/localpng.h"|' \
		${WRKSRC}/src/frontend/mame/ui/icorender.cpp

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} html SPHINXBUILD=sphinx-build-${PYTHON_VER})
	@${RM} ${WRKSRC}/docs/build/html/.buildinfo

post-build:
	(cd ${WRKSRC}/docs && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} man SPHINXBUILD=sphinx-build-${PYTHON_VER})

do-install:
.for DATA in artwork bgfx ctrlr ini hash language plugins samples
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${DATA} ${STAGEDIR}${DATADIR})
.endfor

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/build/man/MAME.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/mame.6 \
		${STAGEDIR}${MANPREFIX}/man/man6

	${MKDIR} ${STAGEDIR}${ETCDIR}
.for INI in mame plugin ui
	${INSTALL_DATA} ${WRKDIR}/${INI}.ini \
		${STAGEDIR}${ETCDIR}/${INI}.ini.sample
.endfor

do-install-DEBUG-on:
	${INSTALL_PROGRAM} ${WRKSRC}/mamed \
		${STAGEDIR}${PREFIX}/bin/mame

do-install-DEBUG-off:
	${INSTALL_PROGRAM} ${WRKSRC}/mame \
		${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/build && \
		${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

do-install-TOOLS-on:
.for PROGRAM in castool chdman floptool imgtool jedutil ldresample ldverify \
	nltool nlwav pngcmp regrep romcmp split srcclean testkeys unidasm
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} \
		${STAGEDIR}${PREFIX}/bin
.endfor

.for MANUAL in castool chdman floptool imgtool jedutil ldplayer ldresample \
	ldverify romcmp
	${INSTALL_MAN} ${WRKSRC}/docs/man/${MANUAL}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
