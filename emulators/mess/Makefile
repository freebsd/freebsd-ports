# Created by: alepulver
# $FreeBSD$

PORTNAME=	mess
PORTVERSION=	0.154${PATCHSUFFIX}
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://mamedev.mameworld.info/releases/ \
		http://emumovies.com/aarongiles/releases/ \
		http://mamedev.org/updates/:patchsets
DISTFILES=	mame${PORTVERSION:S/.//:C/p[0-9]*$//}s${EXTRACT_SUFX} \
		${UPDATE_PATCHES:C/$/.zip:patchsets/}
DIST_SUBDIR=	mame

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple Emulator Super System

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	liberation-fonts-ttf>=0:${PORTSDIR}/x11-fonts/liberation-fonts-ttf

NO_WRKSUBDIR=	yes

USES=		dos2unix gmake pkgconfig shebangfix zip
DOS2UNIX_FILES=	src/lib/lib7z/CpuArch.h \
		src/lib/lua/luaconf.h \
		src/osd/eigccx86.h \
		src/osd/eminline.h \
		src/osd/sdl/osinline.h \
		src/osd/sdl/sdlsync_ntc.c \
		src/osd/sdl/sdlsync_os2.c
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
		TARGET="${PORTNAME}" FULLNAME="${PORTNAME}" \
		SDL_NETWORK="pcap"
MAKEFILE=	makefile

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		BUILTIN_DEBUGGER DEBUG DOCS EXAMPLES SDL2

BUILTIN_DEBUGGER_DESC=	Builtin debugger support
BUILTIN_DEBUGGER_USE=	QT4=gui,moc_build,qmake_build
BUILTIN_DEBUGGER_MAKE_ENV_OFF=\
			NO_DEBUGGER=1 NO_USE_QTDEBUG=1
DEBUG_MAKE_ENV=		DEBUG=1
SDL2_DESC=		SDL2 libraries support
SDL2_USE=		SDL=sdl2,ttf2
SDL2_MAKE_ENV=		SDL_LIBVER="sdl2"

PATCHLEVEL=	# none

.if defined(PATCHLEVEL) && ${PATCHLEVEL}
PATCHSUFFIX=	p${PATCHLEVEL}
UPDATE_PATCHES!=	/usr/bin/jot -s " " \
		-w ${PORTVERSION:S/.//:C/\.p[0-9]*$//}u%d_diff \
		${PATCHLEVEL} 1 ${PATCHLEVEL}
.endif

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MSDL2)
USE_SDL=	sdl ttf
.endif

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
		's|^\(BUILD_EXPAT \)|#\1| ; \
		 s|^\(BUILD_ZLIB \)|#\1| ; \
		 s|^\(BUILD_FLAC \)|#\1| ; \
		 s|^\(BUILD_JPEGLIB \)|#\1| ; \
		 s|^\(CC \)|#\1| ; \
		 s|^\(LD \)|#\1| ; \
		 s|^\(PYTHON \)|#\1| ; \
		 s|-O$$(OPTIMIZE)|| ; \
		 /--warn-common/s|= -Wl,|= $$(GCC_LDFLAGS) -Wl,| ; \
		 /LDFLAGS/s|-s|| ; \
		 /LIBS/s|-lstdc++|| ; \
		 /LIBS/s|-lpthread|-pthread|' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		'/LIBS/s|-lpthread|-pthread| ; \
		 /-isystem/s|^|#| ; \
		 /X11R6/s|^|#|' ${WRKSRC}/src/osd/sdl/sdl.mak

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.for F in castool chdman imgtool jedutil ldresample ldverify romcmp \
	testkeys unidasm
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${F} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME})
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} artwork ${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} hash ${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC}/src/osd/sdl && ${COPYTREE_SHARE} keymaps \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${FILESDIR} && ${INSTALL_DATA} mess.ini ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
