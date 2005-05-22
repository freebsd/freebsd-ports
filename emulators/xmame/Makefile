# New ports collection makefile for:    xmame
# Date created:         4 Sep 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	xmame
PORTVERSION?=	0.96
CATEGORIES=	emulators
MASTER_SITES=	http://x.mame.net/download/:xmame \
		http://www.arcade-history.com/download/:history \
		http://www.mameworld.net/highscore/:highscore \
		http://cheat.retrogames.com/:cheat
DISTNAME=	xmame-${XMAMEVERSION:S/.r/-rc/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:xmame
DIST_SUBDIR=	xmame

MAINTAINER?=	flynn@energyhq.es.eu.org
COMMENT?=	UNIX/X11 port of the Multi Arcade Machine Emulator (MAME)

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
MAKE_ARGS+=	ARCH=freebsd
USE_REINPLACE=	yes
WANT_SDL=	yes
WANT_GNOME=	yes

# Broken on ia-64
NOT_FOR_ARCHS=	ia64

# Are we building MAME, MESS or PinMAME? (also set by slave ports)
MAMEMESS?=	mame

MAN6=		x${MAMEMESS}.6

OPTIONS=	SDL		"Use the SDL driver" on \
		OPENGL		"Use the OpenGL driver" off \
		X11		"Use the X11 driver" off \
		SVGALIB		"Use the Svgalib driver" off \
		ASM68K		"Enable the speedier but buggy 68k emulator" off \
		OPTIMIZATION	"Enable maximum C compiler optimization" off \
		ESOUND		"Enable esound support" off \
		DATFILES	"Installs additional information files" on \
		NETWORK		"Include support for network play (**BROKEN**)" off

XMAMEVERSION?=	${PORTVERSION}

PLIST_SUB+=	MAMEMESS="x${MAMEMESS}" SPOOLGAMES="${SPOOLGAMES}"
.if ${MAMEMESS} == "mame"
PLIST_SUB+=	MAMEONLY="" MESSONLY="@comment " PINMAMEONLY="@comment "
.else
.if ${MAMEMESS} == "mess"
PLIST_SUB+=	MAMEONLY="@comment " MESSONLY="" PINMAMEONLY="@comment "
.else
.if ${MAMEMESS} == "pinmame"
PLIST_SUB+=	MAMEONLY="@comment " MESSONLY="@comment " PINMAMEONLY=""
.else
.error MAMEMESS must be set to one of "mame", "mess" or "pinmame".
.endif
.endif
.endif

# Where do we want game spool data?
SPOOLGAMES?=	/var/games

# Docs list
GENERALDOCS=	changes.unix \
		dga2.txt \
		img/xmame.jpg \
		liesmich.unix \
		multiplayer-readme.txt \
		xmame-doc-2.html \
		xmame-doc-3.html \
		xmame-doc-4.html \
		xmame-doc-5.html \
		xmame-doc-6.html \
		xmame-doc-7.html \
		xmame-doc.html \
		xmame-doc.lyx \
		xmame-doc.txt \
		xmame-gdoc-1.html \
		xmame-gdoc-2.html \
		xmame-gdoc-3.html \
		xmame-gdoc-4.html \
		xmame-gdoc-5.html \
		xmame-gdoc-6.html \
		xmame-gdoc-7.html \
		xmame-gdoc-8.html \
		xmame-gdoc.html \
		xmame.css
XMAMEDOCS=
XMESSDOCS=	mess/credits.htm \
		mess/faq.htm \
		mess/imgtool.txt \
		mess/messnew.txt \
		mess/messroms.txt \
		mess/sysinfo.dat \

PINMAMEDOCS=	pinmame/simulation.txt \
		pinmame/whatsnew.txt \
		pinmame/pinmame.txt \
		pinmame/gamelist.txt \
		pinmame/keys.txt \
		pinmame/sounds.dat
GLDOCS=		changes.opengl
.if ${MAMEMESS} == "mame"
ALLDOCS=	${GENERALDOCS} ${XMAMEDOCS}
.else
.if ${MAMEMESS} == "mess"
ALLDOCS=	${GENERALDOCS} ${XMESSDOCS}
.else
ALLDOCS=	${GENERALDOCS} ${PINMAMEDOCS}
.endif
.endif

#
# Various options are processed here.
#
.include <bsd.port.pre.mk>

# Option WITH_DATFILES
.if ${MAMEMESS} == "mame"

.if defined(WITH_DATFILES)
PLIST_SUB+=	DATFILES=""

EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

#HIVER=		795

DISTFILES+=	uhsdat${PORTVERSION:S/.//}.zip:highscore \
		history${PORTVERSION:S/./_/}.zip:history \
		cheat.zip:cheat
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

post-extract:
	cd ${WRKDIR} && \
		${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/uhsdat${PORTVERSION:S/.//}.zip \
			hiscore.dat
	cd ${WRKDIR} && \
		${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/history${PORTVERSION:S/./_/}.zip \
			history.dat
	cd ${WRKDIR} && \
		${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/cheat.zip cheat.dat
.else
PLIST_SUB+=	DATFILES="@comment "
.endif
.else # xmess
PLIST_SUB+=	DATFILES="@comment "
.endif

.if defined(WITH_ASM68K)
ASM_COMMENT=
.else
ASM_COMMENT=\#
.endif

# Option WITH_OPTIMIZATION
.if defined(WITH_OPTIMIZATION)
CFLAGS+=	-O3 -Wall -Wno-unused -funroll-loops \
		-fstrength-reduce -fomit-frame-pointer -ffast-math \
		-falign-functions=4 -falign-jumps=4 -falign-loops=4
.endif

SDLSOUNDCOMMENT=	\#

# Option DISPLAY_TARGET
.if defined(WITH_SDL) || !defined(WITHOUT_SDL)
USE_SDL=	sdl
DISPLAY_TARGET=	sdl
DISPLAY_METHOD=	SDL
SDLSOUNDCOMMENT=
.endif

.if defined(WITH_OPENGL)
USE_XLIB=	yes
DISPLAY_TARGET=	opengl
CFLAGS+=	${PTHREAD_CFLAGS} -I${X11BASE}/include
USE_GL=		yes
DISPLAY_METHOD=	x11
PLIST_SUB+=	OPENGL=""
ALL_DOCS+=	${GLDOCS}
.else
PLIST_SUB+=	OPENGL="@comment "
.endif

.if defined(WITH_SVGALIB)
DISPLAY_TARGET=	svgalib
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
USE_XPM=	yes
DISPLAY_METHOD=	svgalib
.endif

.if defined(WITH_X11)
DISPLAY_METHOD=	x11
USE_XLIB=	yes
.endif

# Option WITH_ESOUND
.if defined(WITH_ESOUND)
ESOUNDCOMMENT=
USE_GNOME=	esound
.else
ESOUNDCOMMENT=\#
.endif

# XXX Network support is *broken* in 0.85+, leave commented out for now
# Option WITH_NETWORK
.if defined(WITH_NETWORK)
BROKEN=	"Networking support is currently broken"
NETWORK=
.else
NETWORK=\#
.endif

# The large number of sed regexes here is intended to make this port a whole
# lot easier to maintain - please don't convert them into a patch.
do-configure:
	${REINPLACE_CMD} -e "s@= gcc@?=  ${CC}@g" \
		-e "s@^TARGET.*@TARGET = ${MAMEMESS}@g" \
		-e "s@# XMAME_NET@${NETWORK}XMAME_NET@g" \
		-e "s@# X86_ASM_68000 =@${ASM_COMMENT}X86_ASM_68000 =@g" \
		-e "s@^CFLAGS.*@CFLAGS ?= ${CFLAGS}@g" \
		-e "s@^INSTALL_GROUP.*@INSTALL_GROUP = wheel@g" \
		-e "s@# LIBS.*@LIBS = -L${LOCALBASE}/lib@g" \
		-e "s@# INCLUDES.*@INCLUDES = -I${LOCALBASE}/include@g" \
		-e "s@^PREFIX.*@PREFIX = ${PREFIX}@g" \
		-e "s@/share/man@/man@g" \
		-e "s@^MY_CPU.*@MY_CPU = ${ARCH}@g" \
		-e "s@^ARCH.*@ARCH = freebsd@g" \
		-e "s@# JOY_USB@JOY_USB@g" \
		-e "s@# SOUND_ESOUND@${ESOUNDCOMMENT}SOUND_ESOUND@g" \
		-e "s@# SOUND_SDL@${SDLSOUNDCOMMENT}SOUND_SDL@g" \
		-e "s@^DISPLAY_METHOD.*@DISPLAY_METHOD = ${DISPLAY_METHOD}@g" \
		-e "s@# X11_DGA@X11_DGA@g" \
		-e "s@/usr/X11R6@${X11BASE}@g" \
		-e "s@^SDL_CONFIG.*@SDL_CONFIG = ${SDL_CONFIG}@g" \
		-e "s@^GLLIBS += .*@GLLIBS += ${PTHREAD_LIBS}@g" \
			${WRKSRC}/makefile.unix
.if defined(WITH_SDL) || !defined(WITHOUT_SDL)
		${REINPLACE_CMD} -e "s@# JOY_SDL = 1@JOY_SDL = 1@g" ${WRKSRC}/makefile.unix
.endif

.if defined(WITH_OPENGL)
		${REINPLACE_CMD} -e "s@# X11_OPENGL = 1@X11_OPENGL = 1@g" ${WRKSRC}/makefile.unix
.endif

# png.h conflicts with libpng.
.for f in mess/artworkx.c mess/artworkx.h src/artwork.c \
	src/common.c src/png.c src/unix/video-drivers/glexport.c

	${REINPLACE_CMD} -e "s@\"png.h\"@\"mame_png.h\"@g" ${WRKSRC}/${f}

.endfor
	${LN} -s ${WRKSRC}/src/png.h ${WRKSRC}/src/mame_png.h

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} SDL_VIDEODRIVER=aalib \
		${GMAKE} doc/x${MAMEMESS}.6
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} SDL_VIDEODRIVER=aalib \
		${GMAKE} doc/x${MAMEMESS}rc.dist
	@${CP} ${WRKSRC}/doc/x${MAMEMESS}rc.dist \
		${WRKSRC}/doc/x${MAMEMESS}rc.dist.sed
	${SED} -e "s@^spooldir.*\$$@spooldir		${SPOOLGAMES}/x${MAMEMESS}@" \
		-e "s@^rompath.*\$$@rompath			${PREFIX}/share/x${MAMEMESS}/roms@" \
		${WRKSRC}/doc/x${MAMEMESS}rc.dist.sed > ${WRKSRC}/doc/x${MAMEMESS}rc.dist

post-install:
.if ${MAMEMESS} == "mame"
	${INSTALL_PROGRAM} ${WRKSRC}/xml2info ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/romcmp ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/chdman ${PREFIX}/bin
.endif

.if ${MAMEMESS} == "mess"
	${INSTALL_PROGRAM} ${WRKSRC}/imgtool ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dat2html ${PREFIX}/bin
.endif

	${MV} ${PREFIX}/bin/x${MAMEMESS}.${DISPLAY_METHOD} \
		${PREFIX}/bin/x${MAMEMESS}
	${CHOWN} root:games ${PREFIX}/bin/x${MAMEMESS}
	${CHMOD} u-s,g+s ${PREFIX}/bin/x${MAMEMESS}
	${MKDIR} ${PREFIX}/share/x${MAMEMESS} ${PREFIX}/share/x${MAMEMESS}/roms
	${MKDIR} ${SPOOLGAMES}/x${MAMEMESS}
	${CHOWN} -R root:games ${SPOOLGAMES}/x${MAMEMESS}
	${CHMOD} 775 ${SPOOLGAMES}/x${MAMEMESS}
	${INSTALL_DATA} ${WRKSRC}/doc/x${MAMEMESS}rc.dist \
				${PREFIX}/etc/x${MAMEMESS}rc.sample
	${LN} -sf ${PREFIX}/etc/x${MAMEMESS}rc \
				${PREFIX}/share/x${MAMEMESS}/x${MAMEMESS}rc
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/x${MAMEMESS}
	${MKDIR} ${PREFIX}/share/doc/x${MAMEMESS}/img
.for f in ${ALLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${PREFIX}/share/doc/x${MAMEMESS}
.endfor
.endif
.if ${MAMEMESS} == "mess"
	${INSTALL_DATA} ${WRKSRC}/doc/mess/sysinfo.dat \
				${PREFIX}/share/xmess/history.dat
.endif
.if ${MAMEMESS} == "mame" && defined(WITH_DATFILES)
	${INSTALL_DATA} ${WRKDIR}/hiscore.dat ${PREFIX}/share/xmame
	${INSTALL_DATA} ${WRKDIR}/history.dat ${PREFIX}/share/xmame
	${INSTALL_DATA} ${WRKDIR}/cheat.dat ${PREFIX}/share/xmame
.endif
.if defined(WITH_OPENGL)
	@${ECHO_MSG}
	@${ECHO_MSG}	"**************************************************************"
	@${ECHO_MSG}    "* HEADSUP: The OpenGL code is now built on top of the X11"
	@${ECHO_MSG}    "* drivers. You can enable OpenGL rendering with the -vidmode 2"
	@${ECHO_MSG}    "* option."
	@${ECHO_MSG}    "**************************************************************"
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
