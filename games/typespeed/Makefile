# New ports collection makefile for: typespeed
# Date created:        06 September 2003
# Whom:                refugee
#
# $FreeBSD$
#

PORTNAME=	typespeed
PORTVERSION=	0.4.1
CATEGORIES=	games
MASTER_SITES=	http://www.sicom.fi/~bestis/
DISTNAME=	typespeed-${PORTVERSION}

MAINTAINER=	refugee@vt.edu
COMMENT=	Test your typing speed, and get your fingers\' CPS

MAN1=		typespeed.1

USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's#_PREFIX_HERE#${PREFIX}#g' \
		${WRKSRC}/typespeed.h

.include <bsd.port.mk>
