# New ports collection makefile for:   kmpg
# Version required:    0.2.2
# Date created:        24 May 1999
# Whom:                Oscar Bonilla <obonilla@fisicc-ufm.edu>
#
# $FreeBSD$
#

DISTNAME=	kmp3-0.2.2
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/1.1/apps/multimedia/sound

MAINTAINER=	obonilla@fisicc-ufm.edu

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		kdeui.3:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kmp3

.include <bsd.port.mk>
