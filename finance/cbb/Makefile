# New ports collection Makefile for:	cbb
# Version required:     	0.78
# Date created:			24 September, 1998
# Whom:				kline
#
# $FreeBSD$
#

DISTNAME=	cbb-0.78
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp.me.umn.edu/pub/finance/ \
		ftp://ftp.fifi.org/pub/cbb/

MAINTAINER=	kline@thought.org

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=       yes
USE_PERL5=	yes
MAKE_ENV=	PERL5=${PERL5}

.include <bsd.port.mk>
