# New ports collection makefile for:   kdegames
# Version required:    Beta3
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.3 1997/11/05 04:19:49 asami Exp $
#

DISTNAME=	kdegames-Beta3-1
PKGNAME=	kdegames-3.1b
CATEGORIES=	games kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta3/distribution/tgz/source/ \
		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta3/distribution/tgz/source/ \
		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta3/distribution/tgz/source/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[1-9]:${PORTSDIR}/x11/qt \
		gif\\.[23]\\.:${PORTSDIR}/graphics/giflib \
		jpeg\\.[67]\\.:${PORTSDIR}/graphics/jpeg \
		kdecore\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdeui\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		jscript\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		khtmlw\\.0\\.9[1-9]:${PORTSDIR}/x11/kdelibs \
		kfm\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		mediatool\\.0\\.[6-9]:${PORTSDIR}/x11/kdelibs

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=$(PREFIX)/include/giflib"

CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

WRKSRC=		${WRKDIR}/kdegames

.include <bsd.port.mk>
