# New ports collection makefile for:   ptop
# Date created:        18 December 2007
# Whom:                sunghyuk
#
# $FreeBSD$
#

PORTNAME=	ptop
DISTVERSION=	3.6.1b4
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1654/

MAINTAINER=	sunghyuk@gmail.com
COMMENT=	Top clone for postgresql

WRKSRC=	${WRKDIR}/ptop-3.6.1-beta4

MAN1=	ptop.1
USE_GMAKE=	yes
USE_PGSQL=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ptop

.include <bsd.port.mk>
