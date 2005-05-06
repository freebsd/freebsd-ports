# New ports collection makefile for: vavoom
# Date created:		18 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	vavoom
PORTVERSION=	1.17
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	v${PORTVERSION:S/.//}_src

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Doom, Doom II, Heretic, Hexen and Strife source port

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

.ifdef (WITH_OPENAL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
.endif

USE_ZIP=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_SDL=	mixer sdl
USE_GL=		yes
ALL_TARGET=	all sv
ONLY_FOR_ARCHS=	i386

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
MAKE_ARGS=	"USE_SDL=1"

.ifdef (WITH_OPENAL)
MAKE_ARGS+=	"USE_AL=1"
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
BROKEN=		Does not build on FreeBSD 6.X
.endif

.ifndef (WITH_OPENAL)
pre-everything::
	@${ECHO_CMD} "********************************************************************"
	@${ECHO_CMD} "You can define WITH_OPENAL=yes to build Vavoom with 3D sound support"
	@${ECHO_CMD} "********************************************************************"
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|SDL\/||g' ${WRKSRC}/source/*.cpp
.if ${OSVERSION} >= 502126
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/utils/acc/parse.c \
		${WRKSRC}/utils/acc/strlist.c
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Vavoom ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/VavoomSV ${PREFIX}/bin

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

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|; s|%%DATADIR%%|${DATADIR}|' \
		<${PKGMESSAGE}

.include <bsd.port.post.mk>
