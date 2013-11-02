# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	hex
PORTVERSION=	0.0.2
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.earth.li/projectpurple/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of "Puzzle Bobble" for X11 that uses GTK/Imlib

USE_GNOME=	imlib
MAKE_ENV=	GRAPHICPATH="${GRAPHICPATH}" LEVELPATH="${LEVELPATH}"

GRAPHICPATH=	${PREFIX}/share/hex/graphics
LEVELPATH=	${PREFIX}/share/hex/levels

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hex ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${GRAPHICPATH}
	${INSTALL_DATA} ${WRKSRC}/graphics/*.png ${STAGEDIR}${GRAPHICPATH}
	@${MKDIR} ${STAGEDIR}${LEVELPATH}
	${INSTALL_DATA} ${WRKSRC}/levels/Level1 ${STAGEDIR}${LEVELPATH}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in HISTORY README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
