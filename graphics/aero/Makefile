# New ports collection makefile for:    aero
# Version required:     1.5.2
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.4 1996/08/20 13:32:17 erich Exp $
#

DISTNAME=	aero_1.5.2_src
PKGNAME=	aero-1.5.2
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/modellers/aero/

MAINTAINER=	erich@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/lib/libfwf.a:${PORTSDIR}/x11/FWF
RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray
LIB_DEPENDS=    Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X11=	yes
WRKSRC=		work/aero/src

.include <bsd.port.mk>
