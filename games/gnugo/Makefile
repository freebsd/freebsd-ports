# New ports collection makefile for:	gnugo
# Date created:		29 December 1996
# Whom:			jseger@scds.com
#
# $FreeBSD$
#

PORTNAME=	gnugo
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gnugo

MAINTAINER=	spcoltri@omcl.org
COMMENT=	The game of Go

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

INFO=		gnugo
MAN6=		gnugo.6
PLIST_FILES=	bin/gnugo

post-extract:
	${RM} -f ${WRKSRC}/doc/gnugo.info*

.include <bsd.port.mk>
