# New ports collection makefile for:	acorn-media
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	acorn-media
PORTVERSION=	0.3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ecs.soton.ac.uk/pub/worldforge/acorn/0.3/media/ \
		http://65.100.132.89/wf/downloads/acorn/0.3/media/ \
		ftp://two.woovis.com/pub/worldforge/acorn/0.3/media/ \
		http://dreadnought.res.cmu.edu/worldforge/acorn/0.3/media/
DISTNAME=	acorn_media2d-0.3

MAINTAINER=	lehmann@ans-netz.de

NO_BUILD=	YES
WRKSRC=		 ${WRKDIR}/media

do-install:
	${MKDIR} ${PREFIX}/share/forge
	${CP} -r ${WRKSRC} ${PREFIX}/share/forge

.include <bsd.port.mk>
