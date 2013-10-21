# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	asteroid
PORTVERSION=	1.2.1
CATEGORIES=	games

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Modern version of the arcade classic Asteroid

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	chazomaticus
GH_PROJECT=	asteroid
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	ffeb0fd

USES=		cmake
USE_GL=		glut
USE_SDL=	mixer sdl
USE_GNOME=	gtk20
USE_XORG=	xmu
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS NEWS README.md

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
