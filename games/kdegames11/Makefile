# New ports collection makefile for:   kdegames
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdegames
PORTVERSION=	1.1.2
CATEGORIES=	games kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.2/distribution/tar/generic/source/bz2

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		QwSpriteField.7:${PORTSDIR}/converters/kdesupport11

USE_BZIP2=	yes
USE_QT=		yes
GNU_CONFIGURE= yes
USE_GMAKE=	yes
CONFIGURE_ENV= CXXFLAGS="$(CFLAGS)" INSTALL_SCRIPT="install -c -m 555"

.include <bsd.port.mk>
