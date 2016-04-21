# Created by: Tobias Rehbein <tobias.rehbein@web.de>
# $FreeBSD$

PORTNAME=	stonesoup
PORTVERSION=	0.17.1
CATEGORIES=	games
MASTER_SITES=	SF/crawl-ref/Stone%20Soup/${PORTVERSION}
MASTER_SITES=	http://crawl.develz.org/release/
DISTNAME=	stone_soup-${PORTVERSION}-nodeps

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Dungeon Crawl Stone Soup - a fun, free rogue-like game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../licence.txt

BROKEN_powerpc64=	Does not build

USES=		bison compiler:c++11-lib gmake lua:51 perl5 pkgconfig \
		shebangfix sqlite tar:xz

USE_PERL5=	build
SHEBANG_FILES=	util/gen-mi-enum \
		util/good-depfile

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
		DESTDIR=${STAGEDIR} \
		INSTALL_UGRP=root:games \
		NO_AUTO_OPT=YesPlease \
		NO_OPTIMIZE=YesPlease \
		SQLITE_INCLUDE_DIR=${LOCALBASE}/include \
		SQLITE_LIB=-lsqlite3

.include <bsd.port.options.mk>

.if defined(VERBOSE)
MAKE_ARGS+=	V=yes
.endif

.if empty(PORT_OPTIONS:MWIZARD)
MAKE_ARGS+=	NOWIZARD=y
.endif

.if ${PORT_OPTIONS:MSDL}
CONFLICTS+=	${PORTNAME}-[0-9]*
MAKE_ARGS+=	TILES=y \
		GL_INCLUDE="-I ${LOCALBASE}/include/GL"
PLIST_SUB+=	SDL=""
PKGNAMESUFFIX=	-sdl
BUILD_DEPENDS+=	fc-list:x11-fonts/fontconfig \
		${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu
LIB_DEPENDS+=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2
USE_SDL=	sdl2 image2
USE_GL=		yes
.else
USES+=		ncurses
CONFLICTS+=	${PORTNAME}-sdl-[0-9]*
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MSOUND}
RUN_DEPENDS+=	sox:audio/sox
.endif

.if empty(PORT_OPTIONS:MLUA_BINDINGS)
MAKE_ARGS+=	NO_LUA_BINDINGS=yes
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} != clang
CFLAGS+=	-D_GLIBCXX_USE_C99
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
CFLAGS+=	-std=c++11
.endif

post-patch:
#	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/Makefile
.if ${PORT_OPTIONS:MSOUND}
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/AppHdr.h
	@${REINPLACE_CMD} -e "s,%%SOUND%%,," ${WRKSRC}/AppHdr.h
.else
	@${REINPLACE_CMD} -e "s,%%SOUND%%,// ," ${WRKSRC}/AppHdr.h
.endif

pre-install:
	@${FIND} ${WRKSRC}/dat -type f -name '*.orig' | \
		${XARGS} ${RM}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${STAGEDIR}${DATADIR}/settings/init.txt ${STAGEDIR}${EXAMPLESDIR}/sample.crawlrc

.include <bsd.port.post.mk>
