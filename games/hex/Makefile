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

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hex ${PREFIX}/bin
	@${MKDIR} ${GRAPHICPATH}
	${INSTALL_DATA} ${WRKSRC}/graphics/*.png ${GRAPHICPATH}
	@${MKDIR} ${LEVELPATH}
	${INSTALL_DATA} ${WRKSRC}/levels/Level1 ${LEVELPATH}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/hex
.for file in HISTORY README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hex
.endfor
.endif

.include <bsd.port.mk>
