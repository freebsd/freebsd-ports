# New ports collection makefile for:   kdesupport
# Version required:    Beta1
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.1.1.1 1997/11/03 00:36:01 se Exp $
#

DISTNAME=	kdesupport-Beta1-2
PKGNAME=	kdesupport-1.2b
CATEGORIES=	converters kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta1/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta1/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta1/distribution/tgz/source/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.[0-9]:${PORTSDIR}/x11/qt

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--x-inc=$(X11BASE)/include -I$(PREFIX)/include -I$(PREFIX)/include/giflib" \
		"--x-lib=$(X11BASE)/lib -L$(PREFIX)/lib" \
		"--datadir=$(PREFIX)/share/kde" \
		"--without-gnu-ld" \
		"--without-libjpeg" \
		"--without-libgif" \
		"--without-libgdbm"

WRKSRC=		${WRKDIR}/kdesupport

.include <bsd.port.mk>
