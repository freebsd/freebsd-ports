# New ports collection makefile for:   kdegames
# Version required:    Beta3
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.27 1999/02/08 22:25:47 se Exp $
#

DISTNAME=	kdegames-1.1
CATEGORIES=	games kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1/distribution/tar/generic/source

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		QwSpriteField.6:${PORTSDIR}/converters/kdesupport11

USE_QT=		yes
HAS_CONFIGURE= yes
CONFIGURE_ARGS= "--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"
USE_GMAKE=	yes

CONFIGURE_ENV= CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

.include <bsd.port.mk>
