# New ports collection makefile for:   kdegraphics
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdegraphics
PORTVERSION=	1.1.2
CATEGORIES=	graphics kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.2/distribution/tar/generic/source/bz2

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.3:${PORTSDIR}/x11/kdelibs11

NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-qt-includes=${QTDIR}/include/X11/qt" \
		"--with-extra-includes=${LOCALBASE}/include" \
		"--with-extra-libs=${LOCALBASE}/lib"
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555" \
		QTDIR=${QTDIR}
CFLAGS+=	"-I${PREFIX}/include"
USE_GMAKE=	yes

.if defined(PREFIX)
QTDIR?=		${PREFIX}
.else
QTDIR?=		${X11BASE}
.endif

.include <bsd.port.mk>
