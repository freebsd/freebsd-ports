# New ports collection makefile for:	kdesupport2
# Date created:				Sun May 14 2000 01:14:20
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdesupport
PORTVERSION=	1.90
CATEGORIES=	converters kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR=	unstable/distribution/tar/src

MAINTAINER=	will@FreeBSD.org

MOC=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
USE_QT2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--without-libjpeg --without-libgif \
		--without-libgdbm --without-libuulib \
		--without-odbc --without-audiofile
CONFIGURE_ENV+=	MOC="${MOC}"
USE_GMAKE=	yes

.include <bsd.port.mk>
