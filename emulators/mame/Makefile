PORTNAME?=	mame
PORTVERSION=	0.250
CATEGORIES=	emulators games

MAINTAINER=	agh@riseup.net
COMMENT?=	MAME: a multi-purpose emulation framework
WWW?=		https://mamedev.org/

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/docs/LICENSE
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/docs/legal/BSD-3-Clause
LICENSE_FILE_GPLv2=	${WRKSRC}/docs/legal/GPL-2.0

ONLY_FOR_ARCHS=	amd64 armv7 i386 powerpc powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	not yet ported to any architecture other than armv7, x86, and powerpc*

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinxcontrib-svg2pdfconverter>0:textproc/py-sphinxcontrib-svg2pdfconverter@${PY_FLAVOR}
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libFLAC.so:audio/flac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpugixml.so:textproc/pugixml
RUN_DEPENDS=	liberation-fonts-ttf>=0:x11-fonts/liberation-fonts-ttf

USES=		compiler:c++14-lang gl gmake jpeg localbase pkgconfig \
		python:3.9,build qt:5 sdl shebangfix sqlite:3 xorg

BINARY_ALIAS=	python3=${PYTHON_CMD} python=${PYTHON_CMD}

USE_GITHUB=	yes
GH_ACCOUNT=	mamedev
GH_PROJECT=	mame # explicit (master port)
GH_TAGNAME=	mame${PORTVERSION:S/.//}
USE_GL=		gl
USE_QT=		buildtools core gui qmake widgets
USE_SDL=	sdl2 ttf2
USE_XORG=	x11 xext xi xinerama xrender

MAKEFILE=	makefile
MAKE_ARGS=	TARGETOS=freebsd \
		TOOLS=1 \
		USE_SYSTEM_LIB_PUGIXML=1 \
		USE_SYSTEM_LIB_SQLITE3=1 \
		VERBOSE=1
MAKE_ENV=	FULLNAME="mame" \
		GCC_LDFLAGS="${LDFLAGS}" \
		LD="${CXX}" \
		NOWERROR=1 \
		OPT_FLAGS="${CXXFLAGS}" \
		PYTHON="${PYTHON_CMD}" \
		SDL_NETWORK="pcap" \
		SUBTARGET="${MSUBTARGET}" \
		TARGET="${MTARGET}" \
		USE_NETWORK=1

SUB_FILES=	pkg-message target.ini
SUB_LIST=	MSUBTARGET=${MSUBTARGET} \
		MTARGET=${MTARGET}

PORTDOCS=	LICENSE html/* legal/*
PORTEXAMPLES=	${MSUBTARGET}.ini

DEBUG_MAKE_ENV=	DEBUG=1

OPTIONS_DEFINE=	DEBUG DOCS EXAMPLES
DEBUG_DESC=	Build with debug profiling and symbols
DOCS_DESC=	Install additional MAME documentation
EXAMPLES_DESC=	Install example ${EMULATOR}.ini configuration

GENIE=		${WRKSRC}/3rdparty/genie
MSUBTARGET?=	mame
MTARGET?=	mame

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	"YES"
MAKE_ENV+=	DEBUG="1" \
		OPTIMIZE="0" \
		PROFILER="1" \
		SYMBOLS="1"
.endif

.if ${ARCH} == amd64 || ${ARCH:Mpowerpc64*}
MAKE_ARGS+=	PTR64=1
.endif

EMULATOR=	${MSUBTARGET}
PLIST_SUB+=	EMULATOR=${EMULATOR}

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} html \
		SPHINXBUILD=sphinx-build-${PYTHON_VER})
	@${RM} ${WRKSRC}/docs/build/html/.buildinfo

do-install:
.if ${MSUBTARGET:Mmame}
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} castool chdman floptool imgtool \
		jedutil ldresample ldverify nltool nlwav pngcmp regrep \
		romcmp split srcclean testkeys unidasm \
		${STAGEDIR}${PREFIX}/bin)
.endif

.for data in artwork bgfx ctrlr ini language hash plugins samples
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${data} ${STAGEDIR}${DATADIR})
.endfor

	${MKDIR} ${STAGEDIR}${DOCSDIR}
.if ${MSUBTARGET:Mmess}
	${INSTALL_MAN} ${WRKSRC}/docs/man/${MTARGET}.6 \
		${STAGEDIR}${MANPREFIX}/man/man6/${EMULATOR}.6
.else
	${INSTALL_MAN} ${WRKSRC}/docs/man/*.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/build/man/*.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/${EMULATOR}.6 \
		${STAGEDIR}${MANPREFIX}/man/man6
	${INSTALL_MAN} ${WRKSRC}/docs/LICENSE ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} legal ${STAGEDIR}${DOCSDIR})
.endif

do-install-DEBUG-off:
.if ${MSUBTARGET:Mmess}
	${INSTALL_PROGRAM} ${WRKSRC}/${MTARGET}${MSUBTARGET} \
		${STAGEDIR}${PREFIX}/bin/${EMULATOR}
.else
	${INSTALL_PROGRAM} ${WRKSRC}/${MSUBTARGET} \
		${STAGEDIR}${PREFIX}/bin/${EMULATOR}
.endif

do-install-DEBUG-on:
.if ${MSUBTARGET:Mmess}
	${INSTALL_PROGRAM} ${WRKSRC}/${MTARGET}${MSUBTARGET}d \
		${STAGEDIR}${PREFIX}/bin/${EMULATOR}
.else
	${INSTALL_PROGRAM} ${WRKSRC}/${MSUBTARGET}d \
		${STAGEDIR}${PREFIX}/bin/${EMULATOR}
.endif

post-build:
.if ${MSUBTARGET:Mmame}
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} man \
		SPHINXBUILD=sphinx-build-${PYTHON_VER}
.endif

post-install-DOCS-on:
.if ${MSUBTARGET:Mmame}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/build && ${COPYTREE_SHARE} html \
		${STAGEDIR}${DOCSDIR})
.endif

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/target.ini \
		${STAGEDIR}${EXAMPLESDIR}/${EMULATOR}.ini

post-patch:
	@${RM} ${WRKSRC}/3rdparty/bx/include/compat/freebsd/dirent.h
	@${RM} ${WRKSRC}/3rdparty/bx/include/compat/freebsd/signal.h
	@${MV} ${GENIE}/build/gmake.freebsd ${GENIE}/build/gmake.bsd
	@${REINPLACE_CMD} -e \
		's|^\(AR \)|#\1| ; \
		 s|^\(CC \)|#\1| ; \
		 s|^\(CXX \)|#\1| ; \
		 s|^\(CXX:\)|#\1| ; \
		 s|^\(LD \)|#\1| ; \
		 s| .(ARCH)||g' \
		 ${WRKSRC}/makefile \
		 ${GENIE}/build/gmake.bsd/genie.make
	@${REINPLACE_CMD} -e 's|gcc|cc|; s|g++|c++|' \
		${GENIE}/src/tools/gcc.lua \
		${GENIE}/src/tools/snc.lua \
		${GENIE}/tests/test_gmake_cpp.lua
	@${REINPLACE_CMD} -e 's|= \"gcc|= \"cc|; s|= \"g++|= \"c++|' \
		-e "s|'CXX =|'#CXX =|; s|'CC  =|'#CC  =|; s| .(ARCH)| |g" \
		${GENIE}/src/host/scripts.c
	@${GREP} -rl '"png.h"' ${WRKSRC}/src | ${XARGS} ${REINPLACE_CMD} \
		-e 's|"png.h"|"localpng.h"|'
	@${REINPLACE_CMD} -e 's|"util/png.h"|"util/localpng.h"|' \
		${WRKSRC}/src/frontend/mame/ui/icorender.cpp
	@${MV} ${WRKSRC}/src/lib/util/png.h ${WRKSRC}/src/lib/util/localpng.h

.include <bsd.port.mk>
