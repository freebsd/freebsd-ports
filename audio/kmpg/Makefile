# New ports collection makefile for:   kmpg
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.7 1998/10/09 10:05:45 asami Exp $
#

DISTNAME=	kmpg-0.3.3
CATEGORIES=	audio kde
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
