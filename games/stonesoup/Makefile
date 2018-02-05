# Created by: Tobias Rehbein <tobias.rehbein@web.de>
# $FreeBSD$

PORTNAME=	stonesoup
PORTVERSION=	0.21.1
CATEGORIES=	games
MASTER_SITES=	https://crawl.develz.org/release/%SUBDIR%/ \
		http://crawl.develz.org/release/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION:C/.[0-9]+$//}
DISTNAME=	stone_soup-${DISTVERSION}

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Dungeon Crawl Stone Soup - a fun, free rogue-like game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../licence.txt

BROKEN_powerpc64=	fails to compile: tool/tile.h: 'nullptr' was not declared in this scope
NOT_FOR_ARCHS=		armv6
NOT_FOR_ARCHS_REASON=	missing platform \#define or unsupported compiler

USES=		bison compiler:c++11-lib gmake lua:51 perl5 pkgconfig \
		shebangfix sqlite tar:xz

USE_PERL5=	build
SHEBANG_FILES=	util/gen-mi-enum \
		util/good-depfile

SAVEDIR=	\~/.stonesoup
WRKSRC=		${WRKDIR}/stone_soup-${PORTVERSION}/source/

SUB_FILES=	README.FreeBSD
PLIST_SUB=	SAVEDIR="${SAVEDIR}"

MAKE_ARGS=	prefix=${PREFIX} \
		DATADIR=${DATADIR} \
		SAVEDIR=${SAVEDIR} \
		DESTDIR=${STAGEDIR} \
		INSTALL_UGRP=root:games \
		NO_AUTO_OPT=YesPlease \
		NO_OPTIMIZE=YesPlease \
		NO_TRY_GOLD=YesPlease \
		POSIX=YesPlease \
		SQLITE_INCLUDE_DIR=${LOCALBASE}/include \
		SQLITE_LIB=-lsqlite3 \
		V=yes

OPTIONS_DEFINE=	SDL SOUND NOWIZARD LUA DOCS EXAMPLES
OPTIONS_DEFAULT=LUA
OPTIONS_SUB=	yes

SOUND_DESC=	Sound support
NOWIZARD_DESC=	Disable Wizard mode
LUA_DESC=	Bindings for LUA user scripts

SDL_CONFLICTS=	${PORTNAME}-[0-9]*
SDL_USE=	sdl=sdl2,image2,mixer2 gl=gl,glu
SDL_USES_OFF=	ncurses
SDL_MAKE_ARGS=	TILES=y SOUND=y
SDL_BUILD_DEPENDS=	\
		fc-list:x11-fonts/fontconfig \
		${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu
SDL_RUN_DEPENDS=	\
		${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu
SDL_LIB_DEPENDS=libpng.so:graphics/png \
		libfreetype.so:print/freetype2
SDL_CONFLICTS_OFF=	${PORTNAME}-sdl-[0-9]*

NOWIZARD_MAKE_ARGS=	NOWIZARD=y
SOUND_MAKE_ARGS=	SOUND=y
SOUND_RUN_DEPENDS=	sox:audio/sox
LUA_MAKE_ARGS_OFF=	NO_LUA_BINDINGS=yes

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} != clang
CFLAGS+=	-D_GLIBCXX_USE_C99
.endif

post-patch-SOUND-on:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/sound.h
	@${REINPLACE_CMD} -e "s,%%SOUND%%,," ${WRKSRC}/sound.h

post-patch-SOUND-off:
	@${REINPLACE_CMD} -e "s,%%SOUND%%,// ," ${WRKSRC}/sound.h

pre-install:
	@${FIND} ${WRKSRC}/dat -type f -name '*.orig' -delete

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${STAGEDIR}${DATADIR}/settings/init.txt ${STAGEDIR}${EXAMPLESDIR}/sample.crawlrc

post-install:
	@${RM} -r ${STAGEDIR}${DATADIR}/settings/mac

.include <bsd.port.post.mk>
