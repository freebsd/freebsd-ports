# New ports collection makefile for:   kdegames
# Version required:    Beta3
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.12 1998/07/13 23:31:47 se Exp $
#

DISTNAME=	kdegames-1.0
CATEGORIES=	games kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.0/distribution/tar/generic/source 

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt133
LIB_DEPENDS=	qt\\.1\\.3[3-9]:${PORTSDIR}/x11/qt133 \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		kdecore\\.1\\.[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.1\\.[0-9]:${PORTSDIR}/x11/kdelibs \
		jscript\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw\\.1\\.[0-9]:${PORTSDIR}/x11/kdelibs \
		kfm\\.1\\.[0-9]:${PORTSDIR}/x11/kdelibs \
		mediatool\\.1\\.[0-9]:${PORTSDIR}/x11/kdelibs \
		QwSpriteField\\.5\\.[2-9]:${PORTSDIR}/converters/kdesupport

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"

CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

.include <bsd.port.mk>
