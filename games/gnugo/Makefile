# New ports collection makefile for:	gnugo
# Date created:		29 December 1996
# Whom:			jseger@scds.com
#
# $FreeBSD$
#

PORTNAME=	gnugo
PORTVERSION=	3.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gnugo

MAINTAINER=	spcoltri@omcl.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN6=		gnugo.6

post-extract:
	${RM} -f ${WRKSRC}/doc/gnugo.info*

.include <bsd.port.mk>
