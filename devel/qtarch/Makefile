# New ports collection makefile for:	qtarch
# Date created:				17 Oct 1998
# Whom:					Frank Gruender
#
# $FreeBSD$
#

PORTNAME=	qtarch
PORTVERSION=	1.4.4
CATEGORIES=	devel
MASTER_SITES=	http://www.qtarch.intranova.net/
DISTNAME=	qtarch-1.4-4

MAINTAINER=	elwood@mc5sys.in-berlin.de

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		kdeui.3:${PORTSDIR}/x11/kdelibs11

FETCH_BEFORE_ARGS=	-b
USE_QT=		yes
USE_GMAKE=	yes
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/qtarch-1.4
MAKE_ENV=	BUILD_RELEASE=yes

.include <bsd.port.mk>
