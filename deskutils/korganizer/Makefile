# New ports collection makefile for:   korganizer
# Version required:    Beta4
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $Id: Makefile,v 1.4 1998/08/07 23:56:14 asami Exp $
#

DISTNAME=	korganizer-0.9
CATEGORIES=	deskutils kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= unstable/apps/office

MAINTAINER=	hanspb@persbraten.vgs.no

LIB_DEPENDS=	gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		kdecore\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs

USE_QT=		yes
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
