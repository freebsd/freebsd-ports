# New ports collection makefile for:    xmame
# Date created:         4 Sep 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	xmame
PORTVERSION?=	0.61.1
CATEGORIES=	emulators
MASTER_SITES=	http://x.mame.net/download/:xmame \
		http://www.sys2064.com/files/util/:history \
		http://www.sys2064.com/files/mame/:highscore \
		http://cheat.retrogames.com/:cheat \
		http://www.win.tue.nl/~stijn/xmame/:history,highscore,cheat
DISTNAME=	xmame-${XMAMEVERSION:S/.p/-pr/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:xmame
DIST_SUBDIR=	xmame

MAINTAINER?=	stijn@win.tue.nl

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes

MAN6=		x${MAMEMESS}.6

XMAMEVERSION?=	${PORTVERSION}

# Are we building MAME, MESS or PinMAME? (also set by slave ports)
MAMEMESS?=	mame

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
		ctrlr.txt \
		dga2.txt \
		liesmich.unix \
		listinfo.txt \
		multiplayer-readme.txt \
		xmame-doc-1.html \
		xmame-doc-2.html \
		xmame-doc-3.html \
		xmame-doc-4.html \
		xmame-doc-5.html \
		xmame-doc-6.html \
		xmame-doc-7.html \
		xmame-doc-8.html \
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
XMAMEDOCS=	changes.mame \
		gamelist.mame \
		readme.mame
XMESSDOCS=	changes.mess \
		credits.mess \
		gamelist.mess \
		imgtool.txt \
		messhelp.txt \
		messroms.txt \
		old-changes.mess
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

PKGOPTS=	${FILESDIR}/pkg-opts

#
# Various options are processed here. Note that due to a bug in make(1), at
# present the conditionals are suboptimal. See PR bin/34032.
#

# Option WITH_DATFILES
.if ${MAMEMESS} == "mame"
.if !defined(WITH_DATFILES)
WITH_DATFILES=	yes
.endif

.if ${WITH_DATFILES:L} != "no"
PLIST_SUB+=	DATFILES=""

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

HIVER=		795

DISTFILES+=	uhsdat${HIVER}.zip:highscore history.dat.zip:history \
			cheat.zip:cheat
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

post-extract:
	cd ${WRKDIR} && \
		unzip -q ${DISTDIR}/${DIST_SUBDIR}/uhsdat${HIVER}.zip \
			hiscore.dat
	cd ${WRKDIR} && \
		unzip -q ${DISTDIR}/${DIST_SUBDIR}/history.dat.zip history.dat
	cd ${WRKDIR} && \
		unzip -q ${DISTDIR}/${DIST_SUBDIR}/cheat.zip cheat.dat
.else
PLIST_SUB+=	DATFILES="@comment "
.endif
.endif

# Option WITH_ASM68K
.if !defined(WITH_ASM68K)
WITH_ASM68K=	no
.endif

.if ${WITH_ASM68K:L} == "yes"
ASM_COMMENT=
.else
ASM_COMMENT=\#
.endif

# Option WITH_OPTIMIZATION
.if defined(WITH_OPTIMIZATION)
.if ${WITH_OPTIMIZATION:L} == "yes"
CFLAGS+=	-O3 -Wall -Wno-unused -funroll-loops \
		-fstrength-reduce -fomit-frame-pointer -ffast-math \
		-malign-functions=4 -malign-jumps=4 -malign-loops=4
.endif
.endif

# Option DISPLAY_TARGET
.if !defined(DISPLAY_TARGET)
DISPLAY_TARGET=sdl
.endif

.if ${DISPLAY_TARGET:L} == "opengl"
CFLAGS+=	${PTHREAD_CFLAGS}
USE_MESA=	yes
DISPLAY_METHOD=	xgl
PLIST_SUB+=	OPENGL=""
ALL_DOCS+=	${GLDOCS}
.else
PLIST_SUB+=	OPENGL="@comment "

.if ${DISPLAY_TARGET:L} == "svgalib"
LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	LOCALBASE=${LOCALBASE}
DISPLAY_METHOD=	svgalib
.else

.if ${DISPLAY_TARGET:L} == "x11"
DISPLAY_METHOD=	x11
.else

.if ${DISPLAY_TARGET:L} != "sdl"
pre-everything::
	@${ECHO_MSG} "You must select a valid DISPLAY_TARGET. Refer to"
	@${ECHO_MSG} "'make options' for more information."
	@exit 1
.endif
LIB_DEPENDS=    SDL-1.1.4:${PORTSDIR}/devel/sdl12
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
DISPLAY_METHOD=	SDL
.endif
.endif
.endif

.if ${DISPLAY_TARGET:L} != "svgalib"
USE_XPM=	yes
USE_X_PREFIX=	yes
.endif

PKGNAMESUFFIX=-${DISPLAY_METHOD:L}

# Option WITH_ESOUND
.if !defined(WITH_ESOUND)
WITH_ESOUND=	no
.endif

.if ${WITH_ESOUND:L} == "yes"
ESOUNDCOMMENT=
USE_GNOME=	esound
.else
ESOUNDCOMMENT=\#\ 
.endif

# Option WITH_NETWORK
.if ${MAMEMESS} == "mame"
.if !defined(WITH_NETWORK)
WITH_NETWORK=	yes
.endif

.if ${WITH_NETWORK:L} != "no"
NETWORK=
.else
NETWORK=\#\ 
.endif
.endif

#
# Regular targets
#

options:
	@(${ECHO_MSG} "===>  Build options for ${PKGNAME}:"; \
	  ${PERL} -ne '/^#/ || /^\s/ && print || \
	    print sprintf "* %s [%s]\n	%s", split(/\|/)' ${PKGOPTS}) | \
	  $${PAGER:-/usr/bin/more}

pre-everything::
.if !defined(BATCH)
	@${TEST} -r ${PKGOPTS} && \
	  (${ECHO_MSG} '-------------------------------------------------------------------------'; \
	  ${ECHO_MSG} 'Perform a "make options" to see a list of available installation options.'; \
	  ${ECHO_MSG} '-------------------------------------------------------------------------';)
.endif

# The large number of sed regexes here is intended to make this port a whole
# lot easier to maintain - please don't convert them into a patch.
do-configure:
	${SED} -e "s@= gcc@?=  ${CC}@g" \
		-e "s@^CFLAGS.*@CFLAGS ?= ${CFLAGS}@g" \
		-e "s@lib/x\$$(TARGET)@share/x\$$(TARGET)@g" \
		-e "s@/usr/X11R6@${X11BASE}@g" \
		-e "s@-g bin@-g wheel@g" \
		-e "s@^ARCH  = linux@ARCH  = freebsd@g" \
		-e "s@# X11_XV@X11_XV@g" \
		-e "s@# X11_DGA@X11_DGA@g" \
		-e "s@= x11@= ${DISPLAY_METHOD}@g" \
		-e "s@= mame@= ${MAMEMESS}@g" \
		-e "s@# X86_ASM@${ASM_COMMENT}X86_ASM@g" \
		-e "s@# SOUND_ESOUND@${ESOUNDCOMMENT}SOUND_ESOUND@g" \
		-e "s@# MAME_NET@${NETWORK}MAME_NET@g" \
		-e "s@# LIBS.*@LIBS = -L${LOCALBASE}/lib@g" \
		-e "s@sdl-config@${SDL_CONFIG}@g" \
		-e "s@# JOY_USB@JOY_USB@g" \
		-e "s@GLLIBS=.-ldl@GLLIBS= ${PTHREAD_LIBS}@g" \
			${WRKSRC}/makefile.unix > ${WRKSRC}/Makefile

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
.for file in ${ALLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/x${MAMEMESS}
.endfor
.endif
.if ${MAMEMESS} == "mess"
	${INSTALL_DATA} ${WRKSRC}/doc/sysinfo.dat \
				${PREFIX}/share/xmess/history.dat
.endif
.if ${MAMEMESS} == "mame" && defined(WITH_DATFILES) && ${WITH_DATFILES} == "yes"
	${INSTALL_DATA} ${WRKDIR}/hiscore.dat ${PREFIX}/share/xmame
	${INSTALL_DATA} ${WRKDIR}/history.dat ${PREFIX}/share/xmame
	${INSTALL_DATA} ${WRKDIR}/cheat.dat ${PREFIX}/share/xmame
.endif

.include <bsd.port.mk>
