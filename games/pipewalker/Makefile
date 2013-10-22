# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pipewalker
PORTVERSION=	0.9.1
CATEGORIES=	games
MASTER_SITES=	SF
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A clone of the NetWalk game

GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_GL=		gl glu

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.xpm
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

post-patch:
	@${CHMOD} a+x ${WRKSRC}/install-sh
	@${REINPLACE_CMD} -e 's|(datadir)/games|(datadir)|' \
		${WRKSRC}/data/Makefile.in ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/^install-data-am/ s|install-pkgmenudataDATA||' \
		${WRKSRC}/extra/Makefile.in

.include <bsd.port.mk>
