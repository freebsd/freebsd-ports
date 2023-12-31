PORTNAME=	mame
DISTVERSION=	0.261
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
		asio>0:net/asio \
		genie:devel/genie \
		glm>0:math/glm \
		rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libFLAC.so:audio/flac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libportmidi.so:audio/portmidi \
		libpugixml.so:textproc/pugixml \
		libutf8proc.so:textproc/utf8proc
RUN_DEPENDS=	liberation-fonts-ttf>=0:x11-fonts/liberation-fonts-ttf

USES=		compiler:c++17-lang gl gmake jpeg llvm:min=16 localbase \
		pkgconfig python:3.9,build sdl shebangfix sqlite:3 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	mamedev
GH_TAGNAME=	mame${DISTVERSION:S/.//}
USE_GL=		gl
USE_SDL=	sdl2 ttf2
USE_XORG=	x11 xext xi xinerama xrender

MAKEFILE=	makefile
MAKE_ARGS=	SILENT= \
		verbose=yes
MAKE_ENV=	NO_USE_PORTAUDIO=1 \
		NO_USE_PULSEAUDIO=1 \
		NOWERROR=1 \
		OVERRIDE_AR="llvm-ar${LLVM_VERSION}" \
		OVERRIDE_CC="clang${LLVM_VERSION}" \
		OVERRIDE_CXX="clang++${LLVM_VERSION}" \
		OVERRIDE_LD="lld${LLVM_VERSION}" \
		PRECOMPILE=0 \
		PYTHON_EXECUTABLE="${PYTHON_CMD}" \
		TARGETOS=freebsd \
		USE_PCAP=1 \
		USE_SYSTEM_LIB_ASIO=1 \
		USE_SYSTEM_LIB_EXPAT=1 \
		USE_SYSTEM_LIB_FLAC=1 \
		USE_SYSTEM_LIB_GLM=1 \
		USE_SYSTEM_LIB_JPEG=1 \
		USE_SYSTEM_LIB_PORTMIDI=1 \
		USE_SYSTEM_LIB_PUGIXML=1 \
		USE_SYSTEM_LIB_RAPIDJSON=1 \
		USE_SYSTEM_LIB_SQLITE3=1 \
		USE_SYSTEM_LIB_UTF8PROC=1 \
		USE_SYSTEM_LIB_ZLIB=1 \
		USE_TAPTUN=1

CFLAGS_aarch64=	-march=armv8-a+crc+crypto

EXTRACT_AFTER_ARGS=	${_DIST_EXCLUDES:S,^,--exclude ,}

SUB_FILES=	mame.ini pkg-message plugin.ini ui.ini

PORTDOCS=	html/*

OPTIONS_DEFINE=			DOCS NLS OPENMP QTDEBUGGER SSE2 TOOLS
OPTIONS_RADIO=			BUILDTYPE
OPTIONS_RADIO_BUILDTYPE=	DEBUG SIZE_OPTIMIZED_CFLAGS \
				SPEED_OPTIMIZED_CFLAGS
.if !exists(/usr/include/omp.h)
OPTIONS_EXCLUDE=		OPENMP
.endif
OPTIONS_SUB=			yes

BUILDTYPE_DESC=			Application production type
DEBUG_DESC=			Produce profiling data, and symbols for debugging
DOCS_DESC=			Install extensive online MAME documentation
NLS_DESC=			Install language translations for use in the GUI
QTDEBUGGER_DESC=		Build with Qt interactive low-level machine debugger
SIZE_OPTIMIZED_CFLAGS_DESC=	Optimize for smaller binaries (-Os)
SPEED_OPTIMIZED_CFLAGS_DESC=	Optimize for faster binaries (-O3)
SSE2_DESC=			Build with Streaming SIMD Extensions 2
TOOLS_DESC=			Additional tools for archiving, development, and multimedia

DEBUG_MAKE_ENV=				DEBUG=1 \
					OPTIMIZE=g \
					STRIP_SYMBOLS=0
DEBUG_MAKE_ENV_OFF=			STRIP_SYMBOLS=1
# Attempt to avoid address space exhaustion during linking, specifically
# on armv7, and possibly other architectures:
DEBUG_LDFLAGS_OFF=			-s
NLS_USES=				gettext-runtime
OPENMP_MAKE_ENV=			OPENMP=1
OPENMP_MAKE_ENV_OFF=			OPENMP=0
QTDEBUGGER_USES=			qt:6
QTDEBUGGER_USE=				QT=base,tools:build
QTDEBUGGER_MAKE_ENV=			QT_HOME="${PREFIX}" \
					USE_QTDEBUG=1
QTDEBUGGER_MAKE_ENV_OFF=		USE_QTDEBUG=0
SIZE_OPTIMIZED_CFLAGS_MAKE_ENV=		OPTIMIZE=s
SIZE_OPTIMIZED_CFLAGS_CXXFLAGS=		-Os
SPEED_OPTIMIZED_CFLAGS_MAKE_ENV=	OPTIMIZE=3
SPEED_OPTIMIZED_CFLAGS_CXXFLAGS=	-O3
SSE2_MAKE_ENV=				SSE2=1
SSE2_MAKE_ENV_OFF=			SSE2=0
TOOLS_MAKE_ENV=				TOOLS=1
TOOLS_MAKE_ENV_OFF=			TOOLS=0

# man page for command line utility that is not built at all:
_DIST_EXCLUDES=		docs/man/ldplayer.1
# Libraries, and shaders for proprietary platforms:
_DIST_EXCLUDES+=	"bgfx/shaders/dx*" \
			3rdparty/bgfx/examples/runtime/shaders/dx11 \
			3rdparty/bgfx/examples/runtime/shaders/metal \
			3rdparty/dxsdk bgfx/shaders/metal
# Headers that mask system abstractions required to build MAME:
_DIST_EXCLUDES+=	3rdparty/bx/include/compat/freebsd/dirent.h \
			3rdparty/bx/include/compat/freebsd/signal.h
# Make use of Ports instead of bundled libraries:
_DIST_EXCLUDES+=	3rdparty/expat 3rdparty/glm 3rdparty/libflac \
			3rdparty/libjpeg 3rdparty/portmidi 3rdparty/pugixml \
			3rdparty/rapidjson 3rdparty/sqlite3 \
			3rdparty/utf8proc 3rdparty/zlib
# Bundled libraries not used at all:
_DIST_EXCLUDES+=	3rdparty/genie 3rdparty/portaudio 3rdparty/tap-windows6
# pre-built GENie binaries for other platforms:
_DIST_EXCLUDES+=	3rdparty/bx/tools/bin

.include <bsd.port.options.mk>

.if ${ARCH:Maarch64} || ${ARCH:Mamd64} || ${ARCH:Mpowerpc64*}
MAKE_ENV+=	PTR64=1
.endif

# Compiling with -pg (PROFILE) causes the linker to run out of memory on i386,
# build with less profiling data:
.if ${ARCH:Mi386}
DEBUG_MAKE_ENV+=	PROFILER=1
.else
DEBUG_MAKE_ENV+=	PROFILE=1
.endif

post-extract:
	${MV} ${WRKSRC}/src/lib/util/png.h \
		${WRKSRC}/src/lib/util/localpng.h

post-patch:
# Patch build to use bundled PNG.
	${GREP} -rl '"png.h"' ${WRKSRC}/src | \
		${XARGS} ${REINPLACE_CMD} -e 's|"png.h"|"localpng.h"|'
	${REINPLACE_CMD} -e 's|"util/png.h"|"util/localpng.h"|' \
		${WRKSRC}/src/frontend/mame/ui/icorender.cpp
# Patch build to use GENie from Ports:
	${REINPLACE_CMD} -e 's|%%GENIE_PREFIX%%|${PREFIX}/bin/|' \
	${WRKSRC}/makefile \
		${WRKSRC}/3rdparty/bx/makefile

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} html SPHINXBUILD=sphinx-build-${PYTHON_VER})

post-build:
	(cd ${WRKSRC}/docs && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} man SPHINXBUILD=sphinx-build-${PYTHON_VER})

post-build-TOOLS-on:
.for EXTRA_TOOL in nl virtual
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} SUBTARGET=${EXTRA_TOOL} \
		TOOLS=0)
.endfor

do-install:
.for DATA in artwork bgfx ctrlr ini hash plugins samples
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${DATA} ${STAGEDIR}${DATADIR})
.endfor
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for INI in mame plugin ui
	${INSTALL_DATA} ${WRKDIR}/${INI}.ini \
		${STAGEDIR}${ETCDIR}/${INI}.ini.sample
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}/keymaps
.for KEYMAP in be br ch de es fr gb it pt se
	${INSTALL_DATA} ${WRKSRC}/keymaps/km_${KEYMAP}_LINUX.map \
		${STAGEDIR}${DATADIR}/keymaps/km_${KEYMAP}.map
.endfor
	${INSTALL_MAN} ${WRKSRC}/docs/build/man/${PORTNAME:tu}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/${PORTNAME}.6 \
		${STAGEDIR}${PREFIX}/share/man/man6
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/build && \
		${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -not -regex ^./_sources.*")

do-install-NLS-on:
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} language ${STAGEDIR}${DATADIR} "! -name *.po")

do-install-TOOLS-on:
	${FIND} ${WRKSRC} -depth 1 -type f -and ! -type d -and ! -name ${PORTNAME} \
		-perm -o=+x -exec ${INSTALL_PROGRAM} {} ${STAGEDIR}${PREFIX}/bin/ \
		\;
	${INSTALL_MAN} ${WRKSRC}/docs/man/*.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
