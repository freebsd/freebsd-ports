# New ports collection makefile for:	phpgw_inventory
# Date created:        30 March 2001
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	phpgw_inventory
PORTVERSION=	0.8.2
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpgwapps

MAINTAINER=	olgeni@FreeBSD.org

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/inv

do-install:
		@if [ ! -d ${PREFIX}/www/data.default/phpgroupware ]; then \
			${MKDIR} ${PREFIX}/www/data.default/phpgroupware; \
		fi
		@${CP} -r ${WRKSRC} ${PREFIX}/www/data.default/phpgroupware/

.include <bsd.port.mk>
