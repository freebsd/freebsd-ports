# New ports collection makefile for:   kproject
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.2 1998/08/07 22:17:52 asami Exp $
#

DISTNAME=	kproject-0.1
CATEGORIES=	deskutils kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= /unstable/apps/office
EXTRACT_SUFX=	.tgz

MAINTAINER=	hanspb@persbraten.vgs.no

BUILD_DEPENDS=	moc:${PORTSDIR}/x11-toolkits/qt \
		libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS=	qt\\.1\\.3[1-9]:${PORTSDIR}/x11-toolkits/qt \
		kdecore\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs

WRKSRC=		${WRKDIR}/kproject

.include <bsd.port.mk>
