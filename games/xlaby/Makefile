# New ports collection makefile for:	xlaby
# Date created:				3 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		xlaby
PORTVERSION=		2.0.1
CATEGORIES=		games
MASTER_SITES=		http://www.eleves.ens.fr:8080/home/madore/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
EXTRACT_SUFX=		.tgz

MAINTAINER=		will@FreeBSD.org

USE_IMAKE=		yes
NO_WRKSUBDIR=		yes
MAN6=			xlaby.6
MANCOMPRESSED=		no

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xlaby ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/xlaby.man ${PREFIX}/man/man6/xlaby.6
	@ ${MKDIR} ${PREFIX}/share/doc/xlaby
	@ ${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/xlaby

.include <bsd.port.mk>
