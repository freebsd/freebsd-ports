# ports collection makefile for:	xmysqladmin
# Version required:		0.2.0
# Date created:			Di   2 Sep 1997 16:29:27 CEST
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.14 1999/01/07 08:19:29 simokawa Exp $
#

DISTNAME=	xmysqladmin-0.4.4
CATEGORIES=	databases
MASTER_SITES=	http://www.tcx.se/Contrib/ \
		http://www.buoy.com/mysql/Contrib/ \
		http://web.tryc.on.ca/mysql/Contrib/ \
		http://mysql.acer.net/Contrib/

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms
.if !exists(${PREFIX}/lib/mysql/libmysqlclient.a) || exists(${PREFIX}/lib/mysql/libmysqlclient.so)
LIB_DEPENDS+=	mysqlclient.5:${PORTSDIR}/databases/mysql322
.else
BUILD_DEPENDS=	${PREFIX}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql321
.endif

# depends on xforms
ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/xmysqladmin
USE_X_PREFIX=	yes
ALL_TARGET=	xmysqladmin

.include <bsd.port.mk>
