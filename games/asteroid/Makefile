# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asteroid
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	games@FreeBSD.org
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
LDFLAGS+=	-lm

PORTDOCS=	AUTHORS NEWS README.md
OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
