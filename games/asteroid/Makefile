# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	asteroid
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	SF/chaoslizard/Asteroid/v1.2%20%282012%20Apr.%2022%29/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Modern version of the arcade classic Asteroid

LICENSE=	GPLv3

USE_GL=		glut
USE_SDL=	mixer sdl
USE_GNOME=	gtk20
USE_XORG=	xmu
INSTALLS_ICONS=	yes
USE_CMAKE=	yes
CMAKE_VERBOSE=	yes

PORTDATA=	*
PORTDOCS=	AUTHORS NEWS README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
