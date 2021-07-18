# Created by: Aaron VonderHaar <avh4@usa.net>

PORTNAME=	gnurobots
PORTVERSION=	1.2.0
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU diversion wherein Scheme-coded robots explore a world

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libguile.so:lang/guile1

USES=		autoreconf gnome localbase:ldflags pkgconfig readline
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
