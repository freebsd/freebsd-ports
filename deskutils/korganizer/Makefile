# New ports collection makefile for:   korganizer
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.3 1998/08/07 22:17:52 asami Exp $
#

DISTNAME=	korganizer-0.9
CATEGORIES=	deskutils kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= unstable/apps/office

MAINTAINER=	hanspb@persbraten.vgs.no

BUILD_DEPENDS=	moc:${PORTSDIR}/x11-toolkits/qt
LIB_DEPENDS=	qt\\.1\\.3[1-9]:${PORTSDIR}/x11-toolkits/qt \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		kdecore\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"

CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

WRKSRC=		${WRKDIR}/korganizer

pre-configure:
		${RM} -rf -- $(WRKSRC)/src/.deps $(WRKSRC)/config.cache

.include <bsd.port.mk>
