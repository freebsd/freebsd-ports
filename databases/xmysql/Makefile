# ports collection makefile for:	xmysql
# Version required:		1.5
# Date created:			Tue Sep  2 15:46:09 CEST 1997
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.5 1998/08/05 09:30:47 asami Exp $
#

DISTNAME=	xmysql-1.8
CATEGORIES=	databases
MASTER_SITES=	http://mysql.acer.net/Contrib/ \
		http://www.buoy.com/mysql/Contrib/ \
		http://www.tcx.se/Contrib/ \
                http://web.tryc.on.ca/mysql/Contrib/

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	mysql:${PORTSDIR}/databases/mysql
LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		xforms\\.0\\.:${PORTSDIR}/x11-toolkits/xforms

USE_X_PREFIX=	yes

.include <bsd.port.mk>
