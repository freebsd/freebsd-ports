# ports collection makefile for:	xmysql
# Date created:			Tue Sep  2 15:46:09 CEST 1997
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	xmysql
PORTVERSION=	1.10
CATEGORIES=	databases
MASTER_SITES=	http://web.wt.net/~dblhack/ \
		http://linux.tucows.com/files/x11/office/

MAINTAINER=	dirk@FreeBSD.org

LIB_DEPENDS=	forms.0:${PORTSDIR}/x11-toolkits/xforms \
		mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_X_PREFIX=	yes
USE_XPM=	yes

.include <bsd.port.mk>
