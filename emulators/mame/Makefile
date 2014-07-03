# Created by: alepulver
# $FreeBSD$

PORTNAME=	mame
PORTVERSION=	0.152${PATCHSUFFIX}
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://mame.mirrors.zippykid.com/releases/ \
		http://emumovies.com/aarongiles/releases/ \
		http://mamedev.org/updates/:patchsets
DISTFILES=	${PORTNAME}${PORTVERSION:S/.//:C/p[0-9]*$//}s.zip \
		${UPDATE_PATCHES:C/$/.zip:patchsets/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi Arcade Machine Emulator

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	liberation-fonts-ttf>=0:${PORTSDIR}/x11-fonts/liberation-fonts-ttf

OPTIONS_DEFINE=	BUILTIN_DEBUGGER DEBUG DOCS EXAMPLES SDL2
BUILTIN_DEBUGGER_DESC=	Builtin debugger support
SDL2_DESC=	SDL2 libraries support

NO_WRKSUBDIR=	yes

USES=		dos2unix gmake pkgconfig shebangfix
DOS2UNIX_FILES=	src/emu/netlist/nl_base.h \
		src/emu/netlist/pstate.h
SHEBANG_FILES=	src/emu/cpu/m6502/m6502make.py \
		src/emu/cpu/m6809/m6809make.py \
		src/emu/cpu/mcs96/mcs96make.py \
		src/emu/cpu/tms57002/tmsmake.py
USE_XORG=	xext xi xinerama xrender
USE_GL=		gl
USE_PYTHON_BUILD=2
MAKE_ENV=	NOWERROR=1 USE_NETWORK=1 \
		LD="${CXX}" PYTHON="${PYTHON_CMD}" \
		OPT_FLAGS="${CXXFLAGS}" GCC_LDFLAGS="${LDFLAGS}" \
		TARGET="${PORTNAME}" FULLNAME="${PORTNAME}"
MAKEFILE=	makefile

SUB_FILES=	pkg-message

PATCHLEVEL=	# none

.if defined(PATCHLEVEL) && ${PATCHLEVEL}
PATCHSUFFIX=	p${PATCHLEVEL}
UPDATE_PATCHES!=	/usr/bin/jot -s " " \
		-w ${PORTVERSION:S/.//:C/\.p[0-9]*$//}u%d_diff \
		${PATCHLEVEL} 1 ${PATCHLEVEL}
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBUILTIN_DEBUGGER}
USE_QT4=	gui moc_build qmake_build
.else
MAKE_ENV+=	NO_DEBUGGER=1 NO_USE_QTDEBUG=1
.endif

.if ${PORT_OPTIONS:MSDL2}
USE_SDL=	sdl2 ttf2
MAKE_ENV+=	SDL_LIBVER="sdl2"
.else
USE_SDL=	sdl ttf
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ENV+=	DEBUG=1
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not install on ia64, powerpc, or sparc64
.endif

post-extract:
	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} mame.zip \
		${EXTRACT_AFTER_ARGS})
	@${RM} -f ${WRKDIR}/mame.zip
# Use post-extract target to get in before dos2unix-isation
.if defined(UPDATE_PATCHES)
. for patch in ${UPDATE_PATCHES:S/_/./}
	@${ECHO_MSG} -n "===> Applying upstream development patch ${patch}... "
	@${PATCH} ${PATCH_ARGS} < ${WRKSRC}/${patch}
	@${ECHO_MSG} "[DONE]"
. endfor
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^BUILD_EXPAT /s|^|#| ; \
		 /^BUILD_ZLIB /s|^|#| ; \
		 /^BUILD_FLAC /s|^|#| ; \
		 /^BUILD_JPEGLIB /s|^|#| ; \
		 /^CC /s|^|#| ; \
		 /^LD /s|^|#| ; \
		 /^PYTHON /s|^|#| ; \
		 s|-O$$(OPTIMIZE)|| ; \
		 /--warn-common/s|= -Wl,|= $$(GCC_LDFLAGS) -Wl,| ; \
		 /LDFLAGS/s|-s|| ; \
		 /LIBS/s|-lstdc++|| ; \
		 /LIBS/s|-lpthread|-pthread|' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		'/realloc/s|^|// |' ${WRKSRC}/src/emu/emualloc.h
	@${REINPLACE_CMD} -e \
		'/LIBS/s|-lpthread|-pthread| ; \
		 /-isystem/s|^|#| ; \
		 /X11R6/s|^|#|' ${WRKSRC}/src/osd/sdl/sdl.mak

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.for F in chdman jedutil ldresample ldverify romcmp testkeys unidasm
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${F} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME})
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} artwork ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} hash ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/src/osd/sdl && ${COPYTREE_SHARE} keymaps \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${FILESDIR} && ${INSTALL_DATA} mame.ini ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>
