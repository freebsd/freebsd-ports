# New ports collection makefile for:   kproject
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.8 1998/11/07 18:29:09 fenner Exp $
#

DISTNAME=	kproject-0.1
CATEGORIES=	deskutils kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= unstable/apps/office
EXTRACT_SUFX=	.tgz

MAINTAINER=	hanspb@persbraten.vgs.no

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		kdeui.2:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes
WRKSRC=		${WRKDIR}/kproject

.include <bsd.port.mk>
