# New ports collection makefile for:	gnofin
# Version required:			0.5.10
# Date created:				Sun Jul 18 1999
# Whom:					domi@saargate.de
#
# $FreeBSD$
#

DISTNAME=	gnofin-0.5.10
CATEGORIES=	deskutils
MASTER_SITES=	ftp://jagger.berkeley.edu/pub/darin/gnofin/source/

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs

GTK_CONFIG?=    ${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		gnofin.1

CONFIGURE_ENV=  GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
