# ports collection makefile for:	xmysqladmin
# Date created:			Di   2 Sep 1997 16:29:27 CEST
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	xmysqladmin
PORTVERSION=	1.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mirrors/mysql/Downloads/Contrib

MAINTAINER=	dirk@FreeBSD.org

LIB_DEPENDS=	forms.0:${PORTSDIR}/x11-toolkits/xforms \
		mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	xmysqladmin

.include <bsd.port.mk>
