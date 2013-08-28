# New ports collection makefile for:    xmame
# Date created:         4 Sep 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	xmame
PORTVERSION?=	0.106
PORTREVISION?=	5
CATEGORIES=	emulators
MASTER_SITES=	http://www.franksworld.org/dist/xmame/ \
		http://x.mame.net/download/ \
		http://www.energyhq.es.eu.org/files/ \
		http://www.energyhq.be/files/ \
		http://www.pkix.net/mirror/x.mame.net/
DISTNAME=	xmame-${XMAMEVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	UNIX/X11 port of the Multi Arcade Machine Emulator (MAME)

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

NO_CDROM=	License does not permit selling

USES=		perl5 gmake
USE_GCC=	any
USE_BZIP2=	yes
MAKE_ARGS+=	CC=${CC} ARCH=freebsd
WANT_SDL=	yes
WANT_GNOME=	yes
MAKE_JOBS_UNSAFE=	yes

# Are we building MAME or MESS? (also set by slave ports)
MAMEMESS?=	mame

SUB_FILES=	pkg-message
MAN6=		x${MAMEMESS}.6

OPTIONS_DEFINE=	ASM68K DOCS ESOUND NETWORK OPENGL OPTIMIZATION SDL SVGALIB X11
OPTIONS_DEFAULT=	SDL

SVGALIB_DESC=	Enable Svgalib support
ASM68K_DESC=	Enable the speedier but buggy 68k emulator
OPTIMIZATION_DESC=	Enable maximum C compiler optimization
NETWORK_DESC=	Include support for network play (**BROKEN**)

XMAMEVERSION?=	${PORTVERSION}

DATADIR=	${PREFIX}/share/x${MAMEMESS}
DOCSDIR=	${PREFIX}/share/doc/x${MAMEMESS}
PLIST_SUB+=	MAMEMESS="x${MAMEMESS}" SPOOLGAMES="${SPOOLGAMES}"
.if ${MAMEMESS} == "mame"
PLIST_SUB+=	MAMEONLY="" MESSONLY="@comment "
.else
.if ${MAMEMESS} == "mess"
PLIST_SUB+=	MAMEONLY="@comment " MESSONLY=""
.else
IGNORE=		cannot install: MAMEMESS must be set to one of "mame" or "mess".
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

GLDOCS=		changes.opengl
.if ${MAMEMESS} == "mame"
ALLDOCS=	${GENERALDOCS} ${XMAMEDOCS}
.else
ALLDOCS=	${GENERALDOCS} ${XMESSDOCS}
.endif

#
# Various options are processed here.
#
.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if ${PORT_OPTIONS:MASM68K}
ASM_COMMENT=
.else
ASM_COMMENT=\#
.endif

# Option WITH_OPTIMIZATION
.if ${PORT_OPTIONS:MOPTIMIZATION}
CFLAGS+=	-O3 -Wall -Wno-unused -funroll-loops \
		-fstrength-reduce -fomit-frame-pointer -ffast-math \
		-falign-functions=4 -falign-jumps=4 -falign-loops=4
.endif

SDLSOUNDCOMMENT=	\#

# Option DISPLAY_TARGET
.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
DISPLAY_TARGET=	sdl
DISPLAY_METHOD=	SDL
SDLSOUNDCOMMENT=
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_XORG+=	x11
DISPLAY_TARGET=	opengl
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
USE_GL=		yes
DISPLAY_METHOD=	x11
PLIST_SUB+=	OPENGL=""
ALL_DOCS+=	${GLDOCS}
.else
PLIST_SUB+=	OPENGL="@comment "
.endif

.if ${PORT_OPTIONS:MSVGALIB}
DISPLAY_TARGET=	svgalib
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
USE_XORG+=	xpm
DISPLAY_METHOD=	svgalib
.endif

.if ${PORT_OPTIONS:MX11}
DISPLAY_METHOD=	x11
USE_XORG+=	x11
.endif

# Option WITH_ESOUND
.if ${PORT_OPTIONS:MESOUND}
ESOUNDCOMMENT=
USE_GNOME=	esound
.else
ESOUNDCOMMENT=\#
.endif

# XXX Network support is *broken* in 0.85+, leave commented out for now
# Option WITH_NETWORK
.if ${PORT_OPTIONS:MNETWORK}
BROKEN=	Networking support is currently broken
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
		-e "s@# SOUND_ESOUND@${ESOUNDCOMMENT}SOUND_ESOUND@g" \
		-e "s@# SOUND_SDL@${SDLSOUNDCOMMENT}SOUND_SDL@g" \
		-e "s@^DISPLAY_METHOD.*@DISPLAY_METHOD = ${DISPLAY_METHOD}@g" \
		-e "s@# X11_DGA@X11_DGA@g" \
		-e "s@/usr/X11R6@${LOCALBASE}@g" \
		-e "s@^SDL_CONFIG.*@SDL_CONFIG = ${SDL_CONFIG}@g" \
		-e "s@^GLLIBS += .*@GLLIBS += ${PTHREAD_LIBS}@g" \
			${WRKSRC}/makefile.unix
.if ${OSVERSION} < 800064
	${REINPLACE_CMD} -e "s@# JOY_USB@JOY_USB@g" ${WRKSRC}/makefile.unix
.endif

.if ${PORT_OPTIONS:MSDL}
		${REINPLACE_CMD} -e "s@# JOY_SDL = 1@JOY_SDL = 1@g" ${WRKSRC}/makefile.unix
.endif

.if ${PORT_OPTIONS:MOPENGL}
		${REINPLACE_CMD} -e "s@# X11_OPENGL = 1@X11_OPENGL = 1@g" ${WRKSRC}/makefile.unix
.endif

# png.h conflicts with libpng.
.for f in mess/artworkx.c mess/artworkx.h src/artwork.c \
	src/romload.c src/video.c src/png.c src/unix/video-drivers/glexport.c

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
		-e "s@^rompath.*\$$@rompath			${DATADIR}/roms@" \
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
	${MKDIR} ${DATADIR}/roms
	${MKDIR} ${SPOOLGAMES}/x${MAMEMESS}
	${CHOWN} -R root:games ${SPOOLGAMES}/x${MAMEMESS}
	${CHMOD} 775 ${SPOOLGAMES}/x${MAMEMESS}
	${INSTALL_DATA} ${WRKSRC}/doc/x${MAMEMESS}rc.dist \
				${PREFIX}/etc/x${MAMEMESS}rc.sample
	${LN} -sf ${PREFIX}/etc/x${MAMEMESS}rc \
				${DATADIR}/x${MAMEMESS}rc
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/img
.for f in ${ALLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif
.if ${MAMEMESS} == "mess"
	${INSTALL_DATA} ${WRKSRC}/doc/mess/sysinfo.dat \
				${DATADIR}/history.dat
.endif
.if ${MAMEMESS} == "mame"
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
