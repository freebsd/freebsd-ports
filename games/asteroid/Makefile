# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	asteroid
PORTVERSION=	1.2.1
CATEGORIES=	games

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Modern version of the arcade classic Asteroid

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	chazomaticus
GH_PROJECT=	asteroid
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	6d23595

USE_GL=		glut
USE_SDL=	mixer sdl
USE_GNOME=	desktopfileutils gtk20
USE_XORG=	xmu
INSTALLS_ICONS=	yes
USES=		cmake

PORTDOCS=	AUTHORS NEWS README.md

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@-update-desktop-database -q

.include <bsd.port.mk>
