# New ports collection makefile for: vavoom
# Date created:		18 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	vavoom
PORTVERSION=	1.15.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	v115_2_src

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Doom, Doom II, Heretic, Hexen and Strife source port

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

.ifdef (WITH_OPENAL)
MAKE_ARGS=	"USE_AL=1"
.endif

.ifndef (WITH_OPENAL)
pre-everything::
	@${ECHO_CMD} "********************************************************************"
	@${ECHO_CMD} "You can define WITH_OPENAL=yes to build Vavoom with 3D sound support"
	@${ECHO_CMD} "********************************************************************"
.endif

post-patch:
	cd ${WRKSRC} && ${SH} ${WRKSRC}/fixunix.sh
	@${REINPLACE_CMD} -e 's|SDL\/||g' ${WRKSRC}/source/*.cpp

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

.include <bsd.port.mk>
