# New ports collection makefile for:   kdesupport
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdesupport
PORTVERSION=	1.1.2.1
CATEGORIES=	converters kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1.2/distribution/tar/generic/source/bz2
DISTNAME=	kdesupport-1.1.2

MAINTAINER=	will@FreeBSD.org

USE_BZIP2=	yes

USE_QT=		yes
USE_LIBTOOL=	yes
INSTALLS_SHLIBS=	yes
CONFIGURE_ARGS=	--without-libjpeg --without-libgif \
		--without-libgdbm --without-libuulib
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" INSTALL_SCRIPT="install -c -m 555"

.include <bsd.port.mk>
