# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icebreaker
PORTVERSION=	1.9.8
CATEGORIES=	games
MASTER_SITES=	http://mattdm.org/icebreaker/1.9.x/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Game similar to Jezzball or Barrack

LICENSE=	GPLv2

BUILD_DEPENDS=	pnmtopng:${PORTSDIR}/graphics/netpbm

USE_SDL=	mixer sdl
USE_GMAKE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png \
		share/applications/${PORTNAME}.desktop
PLIST_DIRSTRY=	share/applications

PORTDATA=	*
PORTDOCS=	ChangeLog README README.SDL README.ifyoumakechanges README.themes TODO

MAN6=		${PORTNAME}.6

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
	-e 's|CC=gcc|CC?=g++|' \
	-e 's|sdl-config|$(SDL_CONFIG)|' \
	-e 's|prefix=/usr/local|prefix=${PREFIX}|' \
	-e 's|mandir=$$(prefix)/share/man|mandir=$$(prefix)/man|' \
	-e 's|highscoredir=/var/local/lib/games|highscoredir=/var/games|' \
	-e 's|CFLAGS=|CFLAGS+=|' \
	-e 's|OPTIMIZE=-O3|OPTIMIZE=|' \
	-e 's|$$(CC) $$(CFLAGS) $$^ -o icebreaker $$(SDL_LIB)|$$(CC) $$(LDFLAGS) $$(CFLAGS) $$^ -o icebreaker $$(SDL_LIB)|' \
	-e 's|install -s -g games -m 2755 icebreaker $(bindir)|install -g games -m 2755 icebreaker $(bindir)|' \
	-e 's|install -s -m 755 icebreaker $(bindir)|install -m 755 icebreaker $(bindir)|' \
	-e 's|chown -f games:games|chown -f root:games|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
	-e 's|%{Summary}|Game similar to Jezzball or Barrack|' \
	-e 's|/usr/share/icebreaker/icebreaker_48.bmp|icebreaker|' \
		${WRKSRC}/icebreaker.desktop

post-build:
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/winicontoppm -bestqual icebreaker_32.ico | \
		${LOCALBASE}/bin/pnmtopng > icebreaker.png)

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
