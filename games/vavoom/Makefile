# New ports collection makefile for: vavoom
# Date created:		18 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	vavoom
PORTVERSION=	1.19.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Doom, Doom II, Heretic, Hexen and Strife source port

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	autoconf:259
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-sdl --with-opengl --without-openal --without-vorbis \
		--without-libmad --without-mikmod --without-flac
CONFIGURE_ENV=	"CFLAGS=${CFLAGS} -I${LOCALBASE}/include" \
		"CPPFLAGS=${CPPFLAGS} -I${LOCALBASE}/include" \
		"CXXFLAGS=${CXXFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
		"LDFLAGS=-L${LOCALBASE}/lib -L${X11BASE}/lib"
ALL_TARGET=	all sv
USE_SDL=	mixer sdl
USE_GL=		yes
ONLY_FOR_ARCHS=	i386

.ifdef (WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif

SUB_FILES=	pkg-message vavoom
SUB_LIST=	"PREFIX=${PREFIX}" "PORTSDIR=${PORTSDIR}"

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.pre.mk>

OPENAL_CONFIG?=	${LOCALBASE}/bin/openal-config
.if exists(${OPENAL_CONFIG})
WITH_OPENAL=	yes
.endif

.if exists(${LOCALBASE}/lib/libvorbis.so.3)
WITH_VORBIS=	yes
.endif

.if exists(${LOCALBASE}/lib/libmad.so.2)
WITH_LIBMAD=	yes
.endif

MIKMOD_CONFIG?=	${LOCALBASE}/bin/libmikmod-config
.if exists(${MIKMOD_CONFIG})
WITH_MIKMOD=	yes
.endif

.if exists(${LOCALBASE}/lib/libFLAC.so.7)
WITH_FLAC=	yes
.endif

.ifdef (WITH_OPENAL)
CONFIGURE_ARGS+=	--with-openal
LIB_DEPENDS+=		openal.0:${PORTSDIR}/audio/openal
.endif

.ifdef (WITH_VORBIS)
CONFIGURE_ARGS+=	--with-vorbis
LIB_DEPENDS+=		vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

.ifdef (WITH_LIBMAD)
CONFIGURE_ARGS+=	--with-libmad
LIB_DEPENDS+=		mad.2:${PORTSDIR}/audio/libmad
.endif

.ifdef (WITH_MIKMOD)
CONFIGURE_ARGS+=	--with-mikmod
LIB_DEPENDS+=		mikmod.2:${PORTSDIR}/audio/libmikmod
.endif

.ifdef (WITH_FLAC)
CONFIGURE_ARGS+=	--with-flac
LIB_DEPENDS+=		FLAC.7:${PORTSDIR}/audio/flac
.endif

# -fno-strict-aliasing (default on FreeBSD 6.0+) produces run-working
#  code for `vcc', so use a more conservative setting here
.if (${OSVERSION} >= 600000)
CFLAGS=		-O -pipe
CXXFLAGS=	-O -pipe
.endif

pre-everything::
	@${ECHO_CMD} ""
.ifndef (WITH_OPENAL)
	@${ECHO_CMD} "Define WITH_OPENAL=yes to build with 3D sound support"
.endif
.ifndef (WITH_VORBIS)
	@${ECHO_CMD} "Define WITH_VORBIS=yes to build with Vorbis support"
.endif
.ifndef (WITH_LIBMAD)
	@${ECHO_CMD} "Define WITH_LIBMAD=yes to build MP3 music support"
.endif
.ifndef (WITH_MIKMOD)
	@${ECHO_CMD} "Define WITH_MIKMOD=yes to build with MikMod support"
.endif
.ifndef (WITH_FLAC)
	@${ECHO_CMD} "Define WITH_FLAC=yes to build with FLAC support"
.endif
.ifndef (WITH_OPTIMIZED_CFLAGS)
	@${ECHO_CMD} "Define WITH_OPTIMIZED_CFLAGS=yes to build Vavoom optimized for speed"
.endif
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} -e 's|ALubyte|ALchar|' ${WRKSRC}/source/s_al.cpp
	@${REINPLACE_CMD} -i '' -e 's|SDL\/||g' ${WRKSRC}/source/*.cpp
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/utils/acc/parse.c ${WRKSRC}/utils/acc/strlist.c
	@${REINPLACE_CMD} -e 's|%%SDL_CONFIG%%|${SDL_CONFIG}|g; \
			s|%%OPENAL_CONFIG%%|${OPENAL_CONFIG}|g; \
		s|%%MIKMOD_CONFIG%%|${MIKMOD_CONFIG}|g' ${WRKSRC}/configure.ac
	@(cd ${WRKSRC} && ${SH} ./fixunix.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Vavoom ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/VavoomSV ${PREFIX}/bin

# install wrapper script
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/basev
	${INSTALL_DATA} ${WRKSRC}/basev/default.cfg ${DATADIR}/basev
	${INSTALL_DATA} ${WRKSRC}/basev/startup.vs ${DATADIR}/basev
	${INSTALL_DATA} ${WRKSRC}/basev/games.txt ${DATADIR}/basev
.for i in doom heretic hexen strife
	@${MKDIR} ${DATADIR}/basev/${i}
	${INSTALL_DATA} ${WRKSRC}/basev/${i}/wad0.wad ${DATADIR}/basev/${i}
.endfor
.for i in doom1 doom2 tnt plutonia
	@${MKDIR} ${DATADIR}/basev/${i}
	${INSTALL_DATA} ${WRKSRC}/basev/${i}/wad0.wad ${DATADIR}/basev/${i}
	${INSTALL_DATA} ${WRKSRC}/basev/${i}/base.txt ${DATADIR}/basev/${i}
.endfor

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/vavmref.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/vavoom.txt ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

# Run this target as a user from which you will play Vavoom. It will create
# required symlinks in users home directory. This should be done only once.
installuser:
	cd ${DATADIR} && \
	${FIND} . -type d -exec ${MKDIR} ~/.${PORTNAME}/{} \; && \
	${FIND} . -type f -exec ${LN} -sf ${DATADIR}/{} ~/.${PORTNAME}/{} \;
.if exists(${DMDIR})
	cd ${DMDIR} && \
	${FIND} . -type d -exec ${MKDIR} ~/.${PORTNAME}/{} \; && \
	${FIND} . -type f -exec ${LN} -sf ${DMDIR}/{} ~/.${PORTNAME}/{} \;
.endif

.include <bsd.port.post.mk>
