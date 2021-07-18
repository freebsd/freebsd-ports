# Created by: Pav Lucistnik <pav@FreeBSD.org>

PORTNAME=	crack-attack
PORTVERSION=	1.1.14
PORTREVISION=	17
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OpenGL game based on Super Nintendo classic Tetris Attack

USES=		compiler:c++11-lang gl gnome pkgconfig xorg
USE_XORG=	x11 xi xmu sm ice
USE_GL=		glut
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz \
		share/pixmaps/${PORTNAME}.xpm
PORTDATA=	*

DESKTOP_ENTRIES="Crack Attack!" \
		"${COMMENT}" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

post-patch:
	@${REINPLACE_CMD} -e 's|#ifndef max|#if 0|' ${WRKSRC}/src/Game.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/${PORTNAME}.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
