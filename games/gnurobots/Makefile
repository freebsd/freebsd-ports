PORTNAME=	gnurobots
PORTVERSION=	1.2.0
PORTREVISION=	17
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU diversion wherein Scheme-coded robots explore a world
WWW=		https://www.gnu.org/software/gnurobots/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome guile:1.8 localbase:ldflags pkgconfig readline
USE_GNOME=	vte
GNU_CONFIGURE=	yes

PORTDOCS=	*

CFLAGS+=	-O0

SUB_FILES=	pkg-install pkg-message

DESKTOP_ENTRIES="GNU Robots" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/xpm/robot.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.xpm

post-install-DOCS-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS ChangeLog NEWS README THANKS \
		doc/Robots-HOWTO doc/contrib" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
