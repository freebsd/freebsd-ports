# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pipewalker
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Clone of the NetWalk game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		desktop-file-utils gl localbase sdl
GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_GL=		gl glu

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.xpm
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${CHMOD} a+x ${WRKSRC}/install-sh
	@${REINPLACE_CMD} -e 's|(datadir)/games|(datadir)|' \
		${WRKSRC}/data/Makefile.in ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/^install-data-am/ s|install-pkgmenudataDATA||' \
		${WRKSRC}/extra/Makefile.in

.include <bsd.port.mk>
