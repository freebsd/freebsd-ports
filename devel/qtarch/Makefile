# New ports collection makefile for:	qtarch
# Version required:			1.4-4
# Date created:				17 Oct 1998
# Whom:					Frank Gruender
#
# $Id: Makefile,v 1.1.1.1 1998/12/26 04:30:08 steve Exp $
#

DISTNAME=	qtarch-1.4-4
PKGNAME=	qtarch-1.4.4
CATEGORIES=	devel
MASTER_SITES=	http://www.primenet.com/~jtharris/qtarch/

MAINTAINER=	elwood@mc5sys.in-berlin.de

LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		kdeui.2:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes
USE_GMAKE=	yes
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/qtarch-1.4

MAKE_ENV=	BUILD_RELEASE=yes

.include <bsd.port.mk>
