# New ports collection makefile for:   kmpg
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.1.1.1 1998/06/12 08:05:59 tg Exp $
#

DISTNAME=	kmpg-0.3.3
CATEGORIES=	audio x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= unstable/apps/multimedia/sound
EXTRACT_SUFX=	.tgz

MAINTAINER=	hanspb@persbraten.vgs.no

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[1-9]:${PORTSDIR}/x11/qt \
		kdecore\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs

USE_GMAKE=	yes
MAKE_ENV=	KDEDIR=${PREFIX}

.include <bsd.port.mk>
