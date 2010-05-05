# New ports collection makefile for:   ptop
# Date created:		18 December 2007
# Whom:			Sunghyuk Do <sunghyuk@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ptop
PORTVERSION=	3.6.2
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1781/
DISTNAME=	pg_top-${PORTVERSION}

MAINTAINER=	sunghyuk@gmail.com
COMMENT=	Top clone for postgresql

MAN1=	pg_top.1
USE_GMAKE=	yes
USE_PGSQL=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pg_top

IGNORE=	broken on all supported FreeBSD versions
EXPIRATION_DATE=	2010-03-06

.include <bsd.port.mk>
