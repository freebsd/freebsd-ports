# Created by: alepulver
# $FreeBSD$

PORTNAME?=	mame
PORTVERSION=	0.166
PORTREVISION?=	1
CATEGORIES=	emulators

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Multi Arcade Machine Emulator

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	liberation-fonts-ttf>=0:x11-fonts/liberation-fonts-ttf

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	not yet ported to any arch other than x86

USE_GITHUB=	yes
GH_ACCOUNT=	mamedev
GH_PROJECT=	mame 				# explicit (master port)
GH_TAGNAME=	mame${PORTVERSION:S/.//}

USES=		compiler:c11 gmake jpeg pkgconfig python:2,build shebangfix
SHEBANG_FILES=	src/devices/cpu/m6502/m6502make.py \
		src/devices/cpu/m6809/m6809make.py \
		src/devices/cpu/mcs96/mcs96make.py \
		src/devices/cpu/tms57002/tmsmake.py \
		src/build/*.py
USE_XORG=	x11 xext xi xinerama xrender
USE_GL=		gl
USE_SDL=	sdl2 ttf2
USE_QT4=	gui moc_build qmake_build
MTARGET?=	mame
MSUBTARGET?=	mame
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	NOWERROR=1 USE_NETWORK=1 \
		LD="${CXX}" PYTHON="${PYTHON_CMD}" SDL_LIBVER="sdl2" \
		OPT_FLAGS="${CXXFLAGS}" GCC_LDFLAGS="${LDFLAGS}" \
		TARGET="${MTARGET}" SUBTARGET="${MSUBTARGET}" FULLNAME="mame" SDL_NETWORK="pcap"
MAKE_ARGS=	TARGETOS=freebsd VERBOSE=1 TOOLS=1
MAKEFILE=	makefile
GENIE=		${WRKSRC}/3rdparty/genie
PORTDOCS=	*
PORTEXAMPLES=	${MSUBTARGET}.ini

SUB_FILES=	pkg-message target.ini
SUB_LIST=	MTARGET=${MTARGET} MSUBTARGET=${MSUBTARGET}

OPTIONS_DEFINE=		DEBUG DOCS EXAMPLES
DEBUG_MAKE_ENV=		DEBUG=1

.include <bsd.port.options.mk>

.if ${ARCH} == amd64
MAKE_ARGS+=	PTR64=1
EMULATOR=	${MSUBTARGET}64
.else
EMULATOR=	${MSUBTARGET}
.endif
PLIST_SUB=	EMULATOR=${EMULATOR}

post-patch:
	@${REINPLACE_CMD} -e \
		's|^\(CC \)|#\1| ; \
		 s|^\(CXX \)|#\1| ; \
		 s|^\(LD \)|#\1| ; \
		 s|^\(PYTHON \)|#\1| ; \
		 s| .(ARCH)|| ; \
		 s|FreeBSD|${OPSYS}|g' \
		 ${WRKSRC}/makefile \
		 ${GENIE}/build/gmake.bsd/genie.make
	@${REINPLACE_CMD} -e 's|gcc|cc|; s|g++|c++|' \
		${GENIE}/src/actions/codelite/codelite_project.lua \
		${GENIE}/src/tools/gcc.lua \
		${GENIE}/src/tools/snc.lua \
		${GENIE}/tests/test_gmake_cpp.lua
	@${REINPLACE_CMD} -e 's|= \"gcc|= \"cc|; s|= \"g++|= \"c++|' \
		-e "s|'CXX =|'#CXX =|; s|'CC  =|'#CC  =|; s| .(ARCH)| |g" \
		${GENIE}/src/host/scripts.c
	# we can't fix two types of python shebangs, so do these manually
	@${REINPLACE_CMD} -i "" -e "s|/usr/bin/env python|${PYTHON_CMD}|" \
		${WRKSRC}/src/build/png*.py
	@${REINPLACE_CMD} -e 's|"python"|"${PYTHON_CMD}"|' \
		${WRKSRC}/scripts/genie.lua
	@${GREP} -rl '"png.h"' ${WRKSRC}/src | ${XARGS} ${REINPLACE_CMD} \
		-e 's|"png.h"|"localpng.h"|'
	@${MV} ${WRKSRC}/src/lib/util/png.h ${WRKSRC}/src/lib/util/localpng.h

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} \
		${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${PREFIX}/libexec/${MSUBTARGET}
	${INSTALL_PROGRAM} ${WRKSRC}/${EMULATOR} ${STAGEDIR}${PREFIX}/bin
.if ${MSUBTARGET:Mmame}
	(cd ${WRKSRC} && \
		${INSTALL_PROGRAM} chdman jedutil ldresample ldverify \
		romcmp testkeys unidasm \
		${STAGEDIR}${PREFIX}/libexec/mame)
.endif
.if ${MSUBTARGET:Mmess}
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} castool chdman imgtool jedutil \
		ldresample ldverify romcmp testkeys unidasm \
		${STAGEDIR}${PREFIX}/libexec/mess)
.endif
	(cd ${WRKSRC} && ${COPYTREE_SHARE} artwork ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} hash ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/src/osd/sdl && \
		${COPYTREE_SHARE} keymaps ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKDIR}/target.ini \
		${STAGEDIR}${EXAMPLESDIR}/${MSUBTARGET}.ini

.include <bsd.port.mk>
