# New ports collection makefile for:    aero
# Version required:     1.5.2
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.9 1998/08/05 09:31:07 asami Exp $
#

DISTNAME=	aero_1.7.0_src
PKGNAME=	aero-1.7.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ee.uwa.edu.au/users/braunl/aero/

MAINTAINER=	erich@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/lib/libfwf.a:${PORTSDIR}/x11-toolkits/FWF
RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray
LIB_DEPENDS=    Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/aero/src
MAKEFILE=	Makefile.linux

.include <bsd.port.mk>
