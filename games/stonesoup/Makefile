# New ports collection makefile for:	dcss
# Date created:		2008-07-11
# Whom:			Tobias Rehbein <tobias.rehbein@web.de>
#
# $FreeBSD$
#

PORTNAME=	stonesoup
PORTVERSION=	0.10.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/crawl-ref/Stone%20Soup/${PORTVERSION}
DISTNAME=	stone_soup-${PORTVERSION}-nodeps

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Dungeon Crawl Stone Soup - a fun, free rogue-like game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/stone_soup-${PORTVERSION}/licence.txt

USE_SQLITE=	yes
USE_XZ=		yes
USE_BISON=	build
USE_GMAKE=	yes
USE_LUA=	5.1
USE_PERL5_BUILD=	yes
USE_GCC=	4.2+

MAKE_JOBS_SAFE=	yes

SAVEDIR=	\~/.stonesoup
WRKSRC=		${WRKDIR}/stone_soup-${PORTVERSION}/source/

SUB_FILES=	README.FreeBSD
PLIST_SUB=	SAVEDIR="${SAVEDIR}"

OPTIONS_DEFINE=	SOUND WIZARD LUA_BINDINGS DOCS EXAMPLES

SOUND_DESC=	Sound support
WIZARD_DESC=	Wizard mode
LUA_BINDINGS_DESC=	Bindings for LUA user scripts

MAKE_ARGS=	prefix=${PREFIX} \
		DATADIR=${DATADIR} \
		SAVEDIR=${SAVEDIR} \
		INSTALL_UGRP=root:games \
		NO_AUTO_OPT=YesPlease \
		NO_OPTIMIZE=YesPlease \
		LUA_INCLUDE_DIR=${LOCALBASE}/include/lua51 \
		LUA_LIB=-llua-5.1 \
		SQLITE_INCLUDE_DIR=${LOCALBASE}/include \
		SQLITE_LIB=-lsqlite3 \
		LDFLAGS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib/lua51"

.include <bsd.port.options.mk>

.if ${CC:T:M*clang*}
MAKE_ARGS+=	NO_INLINE_DEPGEN=1
.endif

.if defined(VERBOSE)
MAKE_ARGS+=	V=yes
.endif

.if empty(PORT_OPTIONS:MWIZARD)
MAKE_ARGS+=	NOWIZARD=y
.endif

.if ${PORT_OPTIONS:MSDL}
CONFLICTS+=	${PORTNAME}-[0-9]*
MAKE_ARGS+=	TILES=y
PLIST_SUB+=	SDL=""
PKGNAMESUFFIX=	-sdl
USE_PKGCONFIG=	yes
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2
USE_SDL=	sdl image
.else
USE_NCURSES=	yes
CONFLICTS+=	${PORTNAME}-sdl-[0-9]*
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MSOUND}
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif

.if empty(PORT_OPTIONS:MLUA_BINDINGS)
MAKE_ARGS+=	NO_LUA_BINDINGS=yes
.endif

post-patch:
.if ${PORT_OPTIONS:MSOUND}
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/AppHdr.h
	@${REINPLACE_CMD} -e "s,%%SOUND%%,," ${WRKSRC}/AppHdr.h
.else
	@${REINPLACE_CMD} -e "s,%%SOUND%%,// ," ${WRKSRC}/AppHdr.h
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README.FreeBSD ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DATADIR}/settings/init.txt ${EXAMPLESDIR}/sample.crawlrc
.endif

.include <bsd.port.mk>
