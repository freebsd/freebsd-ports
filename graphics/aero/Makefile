# New ports collection makefile for:    aero
# Version required:     1.5.2
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id$
#

DISTNAME=	aero_1.5.2_src
PKGNAME=	aero-1.5.2
CATEGORIES+=	x11
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/modellers/aero/
USE_X11=	yes
WRKSRC=		work/aero/src

LIB_DEPENDS=    fwf:${PORTSDIR}/x11/FWF \
                Xpm:${PORTSDIR}/graphics/xpm

EXEC_DEPENDS=	povray:${PORTSDIR}/graphics/povray

.include <bsd.port.mk>
