# New ports collection makefile for:    aero
# Version required:     1.5.2
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.3 1995/10/05 13:54:55 erich Exp $
#

DISTNAME=	aero_1.5.2_src
PKGNAME=	aero-1.5.2
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/modellers/aero/

MAINTAINER=	erich@FreeBSD.org

LIB_DEPENDS=    Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray \
		${X11BASE}/lib/libfwf.a:${PORTSDIR}/x11/FWF

USE_X11=	yes
WRKSRC=		work/aero/src

.include <bsd.port.mk>
