# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	bs
PORTVERSION=	2.10
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/bs/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Battleships solitaire game with a color interface

LICENSE=	BSD3CLAUSE

USES=		gmake ncurses
MAKE_ARGS=	CC="${CC}"
ALL_TARGET=	# empty

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz \
		share/appdata/${PORTNAME}.xml \
		${DESKTOPDIR}/${PORTNAME}.desktop \
		share/icons/hicolor/32x32/apps/battleship.png

PORTDOCS=	NEWS README
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin/|; \
		s|/usr/share/|${PREFIX}/share/|; \
		s|/usr/local/share/man|${PREFIX}/man/|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
