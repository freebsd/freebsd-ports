# New ports collection makefile for:   ktranslator
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $FreeBSD$
#

PORTNAME=	ktranslator
PORTVERSION=	0.4.0
CATEGORIES=	devel kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1/apps/utils

MAINTAINER=	hanspb@persbraten.vgs.no

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		kdeui.3:${PORTSDIR}/x11/kdelibs11 \
		kfm.3:${PORTSDIR}/x11/kdelibs11

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT=		yes

CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

pre-configure:
		${RM} -rf -- $(WRKSRC)/.deps $(WRKSRC)/config.cache

.include <bsd.port.mk>
