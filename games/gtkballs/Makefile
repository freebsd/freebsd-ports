# New ports collection makefile for:	gtkballs
# Version required:			1.02
# Date created:				11 November 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/12/24 07:23:02 steve Exp $
#

DISTNAME=		gtkballs-1.02
CATEGORIES=		games
MASTER_SITES=		ftp://lucifer.dorms.spbu.ru/pub/Linux/games/ \
			http://lucifer.dorms.spbu.ru/gtkballs/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		gtk10.1:${PORTSDIR}/x11-toolkits/gtk10

ALL_TARGET=		gtkballs
MAKEFILE=		makefile
USE_X_PREFIX=		yes
WRKSRC=			${WRKDIR}/gtkballs

MAN6=			gtkballs.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/gtkballs ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/gtkballs.6 ${PREFIX}/man/man6
	@ ${MKDIR} ${PREFIX}/share/gtkballs
	@ ${INSTALL_DATA} ${WRKSRC}/gtkballs-data/*.xpm ${PREFIX}/share/gtkballs
	@ ${INSTALL_DATA} ${WRKSRC}/gtkballs-data/.gtkballs-score ${PREFIX}/share/gtkballs/score
	@ chmod a+rw ${PREFIX}/share/gtkballs/score
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/gtkballs
.for file in COPYING README README.russian TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gtkballs
.endfor
.endif

.include <bsd.port.mk>
