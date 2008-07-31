# New ports collection makefile for:	dcss
# Date created:		2008-07-11
# Whom:			Tobias Rehbein <tobias.rehbein@web.de>
#
# $FreeBSD$
#

PORTNAME=	stonesoup
PORTVERSION=	0.4.2
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	crawl-ref
DISTNAME=	stone_soup-${PORTVERSION}-src
EXTRACT_SUFX=	.tbz2

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Dungeon Crawl Stone Soup - a fun, free rogue-like game

USE_BISON=	build
USE_GMAKE=	yes

SAVEDIR?=	/var/games/${PORTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/source/

SUB_FILES=	README.FreeBSD
PLIST_SUB=	SAVEDIR="${SAVEDIR}"

OPTIONS=	X11		"X11 support"			off \
		SOUND		"sound support"			off \
		LUA_BINDINGS	"LUA bindings for user scripts"	on

.include <bsd.port.pre.mk>

.if defined(WITH_X11)
USE_XORG=	x11
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
MAKEFILE=	makefile.x11
PLIST_SUB+=	X11=""
.else
MAKEFILE=	makefile.unix
PLIST_SUB+=	X11="@comment "
.endif

.if defined(WITH_SOUND)
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif

post-patch:
.for makefile in makefile.unix makefile.x11
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/${makefile}
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," ${WRKSRC}/${makefile}
	@${REINPLACE_CMD} -e "s,%%SAVEDIR%%,${SAVEDIR}," ${WRKSRC}/${makefile}
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/${makefile}
.if defined(WITHOUT_LUA_BINDINGS)
	@${REINPLACE_CMD} -e "s,-DCLUA_BINDINGS,," ${WRKSRC}/${makefile}
.endif
.endfor
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/AppHdr.h
.if defined(WITH_SOUND)
	@${REINPLACE_CMD} -e "s,%%SOUND%%,," ${WRKSRC}/AppHdr.h
.else
	@${REINPLACE_CMD} -e "s,%%SOUND%%,// ," ${WRKSRC}/AppHdr.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in CREDITS README.txt licence.txt
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/${doc} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKDIR}/README.FreeBSD ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DATADIR}/settings/init.txt ${EXAMPLESDIR}/sample.crawlrc
.endif

.include <bsd.port.post.mk>
