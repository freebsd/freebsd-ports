# New ports collection makefile for:	 gnotepad+
# Version required:	1.1.1
# Date created:		08-March-1999
# Whom:			brett@peloton.physics.montana.edu
#
# $Id$
#

DISTNAME=	gnotepad+-1.1.1
CATEGORIES=	editors www
MASTER_SITES=	http://members.xoom.com/ackahn/gnp/

MAINTAINER=	brett@peloton.physics.montana.edu

LIB_DEPENDS=    Xpm.4:${PORTSDIR}/graphics/xpm \
		gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

GNU_CONFIGURE=	yes
CONFIGURE_ENV=  GTK_CONFIG="${X11BASE}/bin/gtk12-config"

MAN1=	gnp.1

.include <bsd.port.mk>
