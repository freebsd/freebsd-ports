# ports collection makefile for:	xmysqladmin
# Version required:		1.0
# Date created:			Di   2 Sep 1997 16:29:27 CEST
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

DISTNAME=	xmysqladmin-1.0
CATEGORIES=	databases
MASTER_SITES=	http://www.tcx.se/Contrib/ \
		http://www.buoy.com/mysql/Contrib/ \
		http://web.tryc.on.ca/mysql/Downloads/Contrib/

MAINTAINER=	andreas@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms \
		mysqlclient.6:${PORTSDIR}/databases/mysql322-client

USE_X_PREFIX=	yes
ALL_TARGET=	xmysqladmin

.include <bsd.port.mk>
