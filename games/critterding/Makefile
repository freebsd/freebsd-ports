# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	critterding
DISTVERSION=	beta12
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/sources

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Evolving Artificial Life

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		autoreconf libtool ncurses pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_GL=		gl
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-system-ftgl
USE_GCC=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	README AUTHORS Changelog

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|../share/critterding|${DATADIR}|' \
		${WRKSRC}/src/gui/textprinter.cpp ${WRKSRC}/src/gl/glwindow.cpp

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
