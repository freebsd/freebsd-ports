# New ports collection makefile for:   korganizer
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $FreeBSD$
#

PORTNAME=	korganizer
PORTVERSION=	1.1
CATEGORIES=	deskutils kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR=	stable/1.1/distribution/tar/generic/source/bz2

MAINTAINER=	hanspb@persbraten.vgs.no

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		kdeui.3:${PORTSDIR}/x11/kdelibs11

USE_BZIP2=	yes
USE_QT=		yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

pre-configure:
		${RM} -rf -- $(WRKSRC)/src/.deps $(WRKSRC)/config.cache

.include <bsd.port.mk>
