# Created by: Steven H. Samorodin (samorodi@NUXI.com)
# $FreeBSD$

PORTNAME=	ishido
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien

MAINTAINER=	samorodi@NUXI.com
COMMENT=	Tile placement game

MAKE_ENV=	X11BASE=${LOCALBASE}
USE_XORG=	x11
MAN6=		ishido.6

NO_STAGE=	yes
do-install:
	${INSTALL_MAN} ${WRKSRC}/ishido.6 ${PREFIX}/man/man6
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g games -m 2511 ${WRKSRC}/ishido ${PREFIX}/bin
	${INSTALL} ${COPY} -o ${BINOWN} -g games -m 664 ${WRKSRC}/ishido_scores  ${PREFIX}/share/misc/ishido_scores

.include <bsd.port.mk>
