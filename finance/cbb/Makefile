# New port makefile for:	cbb
# Version required:     	0.74
# Date created:			24 September, 1998
# Whom:				kline
#
# $Id: Makefile,v 1.1 1998/09/26 01:43:22 kline Exp kline $
#

DISTNAME=	cbb-0.74
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.me.umn.edu/pub/finance/ \
		ftp://ftp.fifi.org/pub/cbb/

MAINTAINER=	kline@thought.org

RUN_DEPENDS=   wish4.2:${PORTSDIR}/x11-toolkits/tk42

NO_BUILD=       yes
USE_PERL5=	yes
MAKE_ENV=	PERL5=${PERL5}

.include <bsd.port.mk>
