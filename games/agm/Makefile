# New ports collection makefile for:	agm
# Date created:				4 July 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	agm
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	http://users.gtn.net/fraserm/

MAINTAINER=	ports@FreeBSD.org

MAN6=		agm.6

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/xagm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/agm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xagm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/agm.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
