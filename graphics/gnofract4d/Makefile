# New ports collection makefile for:	gnofract4d
# Version required:			1.0
# Date created:				30 Dec 1999
# Whom:					Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	gnofract4d-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://download.sourceforge.net/gnofract4d/

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gnomeui.3:${PORTSDIR}/x11/gnomelibs

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${GTK_CONFIG}
CONFIGURE_ARGS+=--datadir=${PREFIX}/share
USE_NEWGCC=	yes

.include <bsd.port.mk>
