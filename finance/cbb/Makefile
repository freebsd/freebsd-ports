# New ports collection Makefile for:	cbb
# Date created:			24 September, 1998
# Whom:				kline
#
# $FreeBSD$
#

PORTNAME=	cbb
PORTVERSION=	0.8.1
CATEGORIES=	finance deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kline@thought.org
COMMENT=	Checkbook balancing tool

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes
USE_PERL5=	yes
MAKE_ENV=	PERL5=${PERL5}
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
