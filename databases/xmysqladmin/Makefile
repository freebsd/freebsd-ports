# ports collection makefile for:	xmysqladmin
# Version required:		0.2.0
# Date created:			Di   2 Sep 1997 16:29:27 CEST
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.5 1998/03/02 18:42:21 andreas Exp $
#

DISTNAME=	xmysqladmin-0.4.4
CATEGORIES=	databases
MASTER_SITES=	http://www.tcx.se/Contrib/ \
		http://www.buoy.com/mysql/Contrib/ \
		http://web.tryc.on.ca/mysql/Contrib/ \
		http://mysql.acer.net/Contrib/

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	mysql:${PORTSDIR}/databases/mysql
LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		xforms\\.0\\.:${PORTSDIR}/x11/xforms

WRKSRC=		${WRKDIR}/xmysqladmin
USE_X_PREFIX=	yes
ALL_TARGET=	xmysqladmin

.include <bsd.port.mk>
