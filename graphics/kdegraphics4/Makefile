# New ports collection makefile for:   kdegraphics
# Version required:    Beta1
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	kdegraphics-1.1.2
CATEGORIES=	graphics kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.2/distribution/tar/generic/source/bz2

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.3:${PORTSDIR}/x11/kdelibs11

USE_BZIP2=	yes
USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"
CFLAGS+=	"-I${PREFIX}/include"
USE_GMAKE=	yes

.include <bsd.port.mk>
