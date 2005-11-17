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

.ifdef (WITH_OPTIMIZED_CFLAGS)
MAKE_ARGS+=	OPT_CFLAGS="-O3 -ffast-math -fomit-frame-pointer"
.endif

SUB_FILES=	pkg-message vavoom
SUB_LIST=	"PREFIX=${PREFIX}" "PORTSDIR=${PORTSDIR}"

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.pre.mk>

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
.if ${OSVERSION} >= 502126
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/utils/acc/parse.c \
		${WRKSRC}/utils/acc/strlist.c
.endif

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
