# New ports collection makefile for:    aero
# Version required:     1.5.2
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.1.1.1 1995/08/28 14:50:51 jkh Exp $
#

DISTNAME=	aero_1.5.2_src
PKGNAME=	aero-1.5.2
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/modellers/aero/

LIB_DEPENDS=    Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
EXEC_DEPENDS=	povray:${PORTSDIR}/graphics/povray
.if !exists(${X11BASE}/lib/libfwf.a)
DEPENDS=	${PORTSDIR}/x11/FWF
.endif

USE_X11=	yes
WRKSRC=		work/aero/src

.include <bsd.port.mk>
