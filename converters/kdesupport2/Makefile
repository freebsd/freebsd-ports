# New ports collection makefile for:   kdesupport
# Version required:    Beta1
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.6 1998/05/09 18:05:24 se Exp $
#

DISTNAME=	kdesupport-beta4-1
PKGNAME=	kdesupport-4.1b
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/Beta4/distribution/tgz/source 
EXTRACT_SUFX=	.src.tar.bz2

MAINTAINER=	se@freebsd.org

BROKEN=		upgrade to 1.0 will be committed within the next few days

BUILD_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2 \
		moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[1-9]:${PORTSDIR}/x11/qt

EXTRACT_CMD=	bzip2
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= | tar -xf -

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--without-libjpeg" \
		"--without-libgif" \
		"--without-libgdbm" \
		"--without-libuulib" \
#		"--with-extra-includes=$(PREFIX)/include/giflib"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

WRKSRC=		${WRKDIR}/kdesupport

.include <bsd.port.mk>
