# ports collection makefile for:	xmysqladmin
# Version required:		0.2.0
# Date created:			Di   2 Sep 1997 16:29:27 CEST
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.17 1999/01/27 18:19:37 fenner Exp $
#

DISTNAME=	xmysqladmin-0.4.4
CATEGORIES=	databases
MASTER_SITES=	http://www.tcx.se/Contrib/ \
		http://www.buoy.com/mysql/Contrib/ \
		http://web.tryc.on.ca/mysql/Downloads/Contrib/ \
		http://mysql.acer.net/Contrib/

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms \
		mysqlclient.6:${PORTSDIR}/databases/mysql322

# depends on xforms
ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/xmysqladmin
USE_X_PREFIX=	yes
ALL_TARGET=	xmysqladmin

.include <bsd.port.mk>
