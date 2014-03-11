# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icebreaker
PORTVERSION=	1.9.8
PORTREVISION=	1 
CATEGORIES=	games
MASTER_SITES=	http://mattdm.org/icebreaker/1.9.x/ \
		SF/nemysisfreebsdp/games/${PORTNAME}/:icons
EXTRACT_SUFX=	.tgz
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Game similar to Jezzball or Barrack

LICENSE=	GPLv2

USES=		gmake
USE_SDL=	mixer sdl

PORTDOCS=	ChangeLog README README.SDL README.ifyoumakechanges \
		README.themes

OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e \
	's|CC=gcc|CC?=gcc|; \
	 s|sdl-config|$(SDL_CONFIG)|; \
	 s|prefix=/usr/local|prefix=${STAGEDIR}${PREFIX}|; \
	 s|datadir=$$(prefix)/share|datadir=${STAGEDIR}${PREFIX}/share|; \
	 s|mandir=$$(prefix)/share/man|mandir=${STAGEDIR}${PREFIX}/man|; \
	 s|highscoredir=/var/local/lib/games|highscoredir=/var/games|; \
	 s|CFLAGS=|CFLAGS+=|; \
	 s|OPTIMIZE=-O3|OPTIMIZE=|; \
	 s|$$(CC) $$(CFLAGS)|$$(CC) $$(LDFLAGS) $$(CFLAGS)|; \
	 s|install -s -g games|install -g games|; \
	 s|install -s -m 755|install -m 755|; \
	 s|chown -f games:games|chown -f root:games|; \
	 s|$$(SRC:.c=.d)|$$(SRC:.c)|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
