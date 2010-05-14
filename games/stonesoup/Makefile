# New ports collection makefile for:	dcss
# Date created:		2008-07-11
# Whom:			Tobias Rehbein <tobias.rehbein@web.de>
#
# $FreeBSD$
#

PORTNAME=	stonesoup
PORTVERSION=	0.6.0
CATEGORIES=	games
MASTER_SITES=	SF/crawl-ref/Stone%20Soup/${PORTVERSION}
DISTNAME=	stone_soup-${PORTVERSION}-nodeps

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Dungeon Crawl Stone Soup - a fun, free rogue-like game

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar

USE_BZIP2=	yes
USE_BISON=	build
USE_GMAKE=	yes
USE_LUA=	5.1
USE_PERL5_BUILD=	yes

MAKE_JOBS_SAFE=	yes

SAVEDIR?=	/var/games/${PORTNAME}
WRKSRC=		${WRKDIR}/stone_soup-${PORTVERSION}/source/

SUB_FILES=	README.FreeBSD
PLIST_SUB=	SAVEDIR="${SAVEDIR}"

OPTIONS=	SDL		"SDL support (tiles interface)"	off \
		SOUND		"Sound support"			off \
		LUA_BINDINGS	"LUA bindings for user scripts"	on \
		UNICODE		"Unicode glyphs (UTF-8)"	off \
		WIZARD		"Wizard mode"			off

MAKEFILE=	makefile
MAKE_ARGS=	FREEBSD_PORT=yes
MAKE_ARGS+=	prefix=${PREFIX} SAVEDIR=${SAVEDIR} DATADIR=${DATADIR}

.include <bsd.port.options.mk>

.if defined(VERBOSE)
MAKE_ARGS+=	V=yes
.endif

.if defined(WITH_WIZARD)
MAKE_ARGS+=	wizard
.endif

.if defined(WITHOUT_SDL)
PLIST_SUB+=	SDL="@comment "
.else
MAKE_ARGS+=	TILES=y
PLIST_SUB+=	SDL=""
PKGNAMESUFFIX=	-sdl
BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2
USE_SDL=	sdl image
.endif

.if defined(WITH_SOUND)
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif

.if defined(WITHOUT_LUA_BINDINGS)
MAKE_ARGS+=	NO_LUA_BINDINGS=yes
.endif

.if defined(WITH_UNICODE)
MAKE_ARGS+=	USE_UNICODE=yes
.endif

post-patch:
.if defined(WITH_SOUND)
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/AppHdr.h
	@${REINPLACE_CMD} -e "s,%%SOUND%%,," ${WRKSRC}/AppHdr.h
.else
	@${REINPLACE_CMD} -e "s,%%SOUND%%,// ," ${WRKSRC}/AppHdr.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README.FreeBSD ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DATADIR}/settings/init.txt ${EXAMPLESDIR}/sample.crawlrc
.endif

.include <bsd.port.mk>
