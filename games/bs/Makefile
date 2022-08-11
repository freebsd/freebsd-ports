PORTNAME=	bs
PORTVERSION=	2.11
CATEGORIES=	games

MAINTAINER=	alfix86@gmail.com
COMMENT=	Battleships solitaire game with a color interface

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlto:textproc/xmlto

USES=		gmake gnome ncurses

MAKE_ARGS=	CC="${CC}"
ALL_TARGET=	# empty

USE_GITLAB=	yes
GL_ACCOUNT=	esr
GL_COMMIT=	73947294765e163a7b914fd6eb4dd364125b3382

PLIST_FILES=	${DESKTOPDIR}/${PORTNAME}.desktop \
		bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz \
		share/appdata/${PORTNAME}.xml \
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
