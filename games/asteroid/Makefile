# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asteroid
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern version of the arcade classic Asteroid

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	chazomaticus
GH_TAGNAME=	64869df

USES=		cmake gl gnome sdl xorg
USE_GL=		gl glu glut
USE_SDL=	mixer sdl
USE_GNOME=	gtk30
USE_XORG=	xmu xi
INSTALLS_ICONS=	yes
LDFLAGS+=	-lm

PORTDOCS=	AUTHORS NEWS README.md
OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
