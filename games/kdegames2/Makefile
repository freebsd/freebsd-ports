# New ports collection makefile for:   kdegames
# Version required:    Beta3
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.20 1998/10/01 18:35:41 brian Exp $
#

DISTNAME=	kdegames
PKGNAME=	kdegames-1.1a1
CATEGORIES=	games kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1pre1/distribution/tar/generic/source
EXTRACT_SUFX=	-1.1-alpha1.src.tar.bz2

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.2:${PORTSDIR}/x11/kdelibs \
		QwSpriteField.6:${PORTSDIR}/converters/kdesupport

EXTRACT_CMD=	bzip2
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= | tar xf -

USE_QT=		yes
HAS_CONFIGURE= yes
CONFIGURE_ARGS= "--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"

CONFIGURE_ENV= CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

.include <bsd.port.mk>
