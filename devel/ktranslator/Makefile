# New ports collection makefile for:   ktranslator
# Version required:    0.4.0
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.2 1999/03/30 19:50:10 taoka Exp $
#

DISTNAME=	ktranslator-0.4.0
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1/apps/utils

MAINTAINER=	hanspb@persbraten.vgs.no

BUILD_DEPENDS=	moc:${PORTSDIR}/x11-toolkits/qt142 \
		msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	qt.2:${PORTSDIR}/x11-toolkits/qt142 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.1:${PORTSDIR}/x11/kdelibs \
		kdeui.1:${PORTSDIR}/x11/kdelibs \
		kfm.1:${PORTSDIR}/x11/kdelibs

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)"

CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

pre-configure:
		${RM} -rf -- $(WRKSRC)/.deps $(WRKSRC)/config.cache

.include <bsd.port.mk>
