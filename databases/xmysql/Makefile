# ports collection makefile for:	xmysql
# Version required:		1.5
# Date created:			Tue Sep  2 15:46:09 CEST 1997
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.1.1.1 1997/09/02 14:56:43 andreas Exp $
#

DISTNAME=	xmysql-1.5
CATEGORIES=	databases
MASTER_SITES=	ftp://mysql.staufen.de/pub/mysql/Contrib/ \
		http://www.tcx.se/Contrib/ \
		http://www.buoy.com/mysql/Contrib/

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	mysql:${PORTSDIR}/databases/mysql
LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		xforms\\.0\\.:${PORTSDIR}/x11/xforms

USE_X11=	yes

.include <bsd.port.mk>
