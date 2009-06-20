# New ports collection makefile for:	dcss
# Date created:		2008-07-11
# Whom:			Tobias Rehbein <tobias.rehbein@web.de>
#
# $FreeBSD$
#

PORTNAME=	stonesoup
PORTVERSION=	0.5
CATEGORIES=	games
MASTER_SITES=	SF/crawl-ref
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

OPTIONS=	SDL		"SDL support (tiles interface)"	off \
		SOUND		"Sound support"			off \
		LUA_BINDINGS	"LUA bindings for user scripts"	on \
		UNICODE		"Unicode glyphs (UTF-8)"	off

.include <bsd.port.options.mk>

.if defined(WITH_SDL)
MAKEFILE=	makefile_tiles.unix
MAKE_JOBS_UNSAFE=	yes
PLIST_SUB+=	SDL=""
USE_SDL=	image
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2
.else
MAKEFILE=	makefile.unix
MAKE_JOBS_SAFE=	yes
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_SOUND)
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif #WITH_SOUND

post-patch:
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e "s,%%SAVEDIR%%,${SAVEDIR}," ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/${MAKEFILE}
.if defined(WITHOUT_LUA_BINDINGS)
	@${REINPLACE_CMD} -e "s,-DCLUA_BINDINGS,," ${WRKSRC}/${MAKEFILE}
.endif
.if defined(WITH_UNICODE)
	@${REINPLACE_CMD} -e "s,%%UNICODE%%,y," ${WRKSRC}/${MAKEFILE}
.else
	@${REINPLACE_CMD} -e "s,%%UNICODE%%,n," ${WRKSRC}/${MAKEFILE}
.endif
.if defined(WITH_SOUND)
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/AppHdr.h
	@${REINPLACE_CMD} -e "s,%%SOUND%%,," ${WRKSRC}/AppHdr.h
.else
	@${REINPLACE_CMD} -e "s,%%SOUND%%,// ," ${WRKSRC}/AppHdr.h
.endif
.if defined(WITH_SDL)
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," ${WRKSRC}/tilesdl.cc
.endif

pre-build:
	@cd ${WRKSRC} && ${GMAKE} depend

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in CREDITS.txt README.txt licence.txt
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/${doc} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKDIR}/README.FreeBSD ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DATADIR}/settings/init.txt ${EXAMPLESDIR}/sample.crawlrc
.endif

.include <bsd.port.mk>
