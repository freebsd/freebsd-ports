# New ports collection makefile for:   kmpg
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.2 1998/07/08 15:00:17 scrappy Exp $
#

DISTNAME=	kmpg-0.3.3
CATEGORIES=	audio x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= unstable/apps/multimedia/sound
EXTRACT_SUFX=	.tgz

MAINTAINER=	hanspb@persbraten.vgs.no

BUILD_DEPENDS=	moc:${PORTSDIR}/x11-toolkits/qt
LIB_DEPENDS=	qt\\.1\\.3[1-9]:${PORTSDIR}/x11-toolkits/qt \
		kdecore\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs

USE_GMAKE=	yes
MAKE_ENV=	KDEDIR=${PREFIX}

.include <bsd.port.mk>
