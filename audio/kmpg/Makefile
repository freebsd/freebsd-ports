# New ports collection makefile for:   kmpg
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.6 1998/09/30 02:07:27 jseger Exp $
#

DISTNAME=	kmpg-0.3.3
CATEGORIES=	audio x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= unstable/apps/multimedia/sound
EXTRACT_SUFX=	.tgz

MAINTAINER=	hanspb@persbraten.vgs.no

LIB_DEPENDS=	kdecore.1:${PORTSDIR}/x11/kdelibs \
		kdeui.1:${PORTSDIR}/x11/kdelibs

BROKEN_ELF=	depends on kdelibs

USE_QT=		yes
USE_GMAKE=	yes
MAKE_ENV=	KDEDIR=${PREFIX}

.include <bsd.port.mk>
