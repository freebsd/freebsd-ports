# New ports collection makefile for: vavoom
# Date created:		18 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	vavoom
PORTVERSION=	1.18
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Doom, Doom II, Heretic, Hexen and Strife source port

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		iconv.3:${PORTSDIR}/converters/iconv

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-sdl --with-opengl --without-openal
CONFIGURE_ENV=	"CXXFLAGS=${CXXFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
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

.ifdef (WITH_OPENAL)
CONFIGURE_ARGS+=	--with-openal
LIB_DEPENDS+=		openal.0:${PORTSDIR}/audio/openal
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
	@${ECHO_CMD} "Define WITH_OPENAL=yes to build Vavoom with 3D sound support"
.endif
.ifndef (WITH_OPTIMIZED_CFLAGS)
	@${ECHO_CMD} "Define WITH_OPTIMIZED_CFLAGS=yes to build Vavoom optimized for speed"
.endif
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|SDL\/||g' ${WRKSRC}/source/*.cpp
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/utils/acc/parse.c ${WRKSRC}/utils/acc/strlist.c
	@${REINPLACE_CMD} -e 's|%%SDL_CONFIG%%|${SDL_CONFIG}|g; \
		s|%%OPENAL_CONFIG%%|${OPENAL_CONFIG}|g' ${WRKSRC}/configure.ac
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
	${FIND} . -type d -exec ${MKDIR} -p ~/.${PORTNAME}/{} \; && \
	${FIND} . -type f -exec ${LN} -sf ${DATADIR}/{} ~/.${PORTNAME}/{} \;
.if exists(${DMDIR})
	cd ${DMDIR} && \
	${FIND} . -type d -exec ${MKDIR} -p ~/.${PORTNAME}/{} \; && \
	${FIND} . -type f -exec ${LN} -sf ${DMDIR}/{} ~/.${PORTNAME}/{} \;
.endif

.include <bsd.port.post.mk>
