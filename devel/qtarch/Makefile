# New ports collection makefile for:	qtarch
# Version required:			1.4-4
# Date created:				17 Oct 1998
# Whom:					Frank Gruender
#
# $FreeBSD$
#

DISTNAME=	qtarch-1.4-4
PKGNAME=	qtarch-1.4.4
CATEGORIES=	devel
MASTER_SITES=	http://www.qtarch.intranova.net/

MAINTAINER=	elwood@mc5sys.in-berlin.de

LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		kdeui.2:${PORTSDIR}/x11/kdelibs11

FETCH_BEFORE_ARGS=	-b
USE_QT=		yes
USE_GMAKE=	yes
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/qtarch-1.4
MAKE_ENV=	BUILD_RELEASE=yes

.include <bsd.port.mk>
