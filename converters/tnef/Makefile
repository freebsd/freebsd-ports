# New ports collection makefile for:	tnef
# Date created:		19 September 2000
# Whom:			Cyrus Rahman <cr@jcmax.com>
#
# $FreeBSD$
#

PORTNAME=	tnef
PORTVERSION=	1.1
CATEGORIES=	converters mail
MASTER_SITES=	http://world.std.com/~damned/

MAINTAINER=	cr@jcmax.com

GNU_CONFIGURE=	yes

MAN1=	tnef.1

pre-configure:
	${MV} ${WRKSRC}/doc/tnef.3 ${WRKSRC}/doc/tnef.1

.include <bsd.port.mk>
