# New ports collection makefile for:	agm
# Date created:				4 July 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		agm
PORTVERSION=		1.4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			http://users.gtn.net/fraserm/
MASTER_SITE_SUBDIR=	games/amusements

MAINTAINER=		ports@FreeBSD.org

MAN6=			agm.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/agm ${PREFIX}/bin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/xagm ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/agm.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
