# ports collection makefile for:	xmysql
# Version required:		1.5
# Date created:			Tue Sep  2 15:46:09 CEST 1997
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.12 1998/11/21 09:58:22 andreas Exp $
#

DISTNAME=	xmysql-1.9
CATEGORIES=	databases
MASTER_SITES=	http://www.tcx.se/Contrib/ \
		http://www.buoy.com/mysql/Contrib/ \
		http://web.tryc.on.ca/mysql/Contrib/

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	mysql:${PORTSDIR}/databases/mysql321
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms

USE_X_PREFIX=	yes

.include <bsd.port.mk>
