PORTNAME=	critterding
DISTVERSION=	beta12
PORTREVISION=	19
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/sources

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Evolving Artificial Life

LIB_DEPENDS=	libfreetype.so:print/freetype2

DEPRECATED=	Abandonware with last release in 2013, newer version bundles depends and requires Qt4
EXPIRATION_DATE=2022-04-16

USES=		autoreconf gl libtool localbase:ldflags ncurses pkgconfig sdl tar:bzip2
GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_GL=		gl
CONFIGURE_ARGS=	--disable-system-ftgl
USE_GCC=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	README AUTHORS Changelog

OPTIONS_DEFINE=	DOCS

BINARY_ALIAS=	freetype-config=true

post-patch:
	@${REINPLACE_CMD} -e 's|../share/critterding|${DATADIR}|' \
		${WRKSRC}/src/gui/textprinter.cpp ${WRKSRC}/src/gl/glwindow.cpp

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
