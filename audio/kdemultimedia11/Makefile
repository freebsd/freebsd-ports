# New ports collection makefile for:   kdemultimedia
# Version required:    Beta1
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.8 1998/05/04 20:22:58 jseger Exp $
#

DISTNAME=	kdemultimedia-1.0pre2-1
PKGNAME=	kdemultimedia-1.0pre2-1
CATEGORIES=	x11
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/latest/distribution/tar/source
EXTRACT_SUFX=	.src.tar.bz2

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2 \
		moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[1-9]:${PORTSDIR}/x11/qt \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		kdecore\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		jscript\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kfm\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		mediatool\\.0\\.[6-9]:${PORTSDIR}/x11/kdelibs

BROKEN=		upgrade

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"

CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

WRKSRC=		${WRKDIR}/kdemultimedia

.include <bsd.port.mk>
