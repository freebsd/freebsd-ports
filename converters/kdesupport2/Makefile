# New ports collection makefile for:   kdesupport
# Version required:    Beta1
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.8 1998/07/19 17:41:45 se Exp $
#

DISTNAME=	kdesupport-1.0
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.0/distribution/tar/generic/source 

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt140
LIB_DEPENDS=	qt\\.1\\.\\\(33\\\|40\\\):${PORTSDIR}/x11/qt140

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--without-libjpeg" \
		"--without-libgif" \
		"--without-libgdbm" \
		"--without-libuulib" \
#		"--with-extra-includes=$(PREFIX)/include/giflib"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

.include <bsd.port.mk>
