# New ports collection makefile for:	kvirc
# Date created:		Mon Feb 15 02:53:29 CET 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	kvirc
PORTVERSION=	2.1.0
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.kvirc.net/kvirc/${PORTVERSION}/source/ \
		ftp://ftp.kvirc.bz.nu/pub/mirror/kvirc/${PORTVERSION}/source/ \
		ftp://kvirc.firenze.linux.it/pub/kvirc/${PORTVERSION}/source/

MAINTAINER=	trevor@FreeBSD.org

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext

ALL_TARGET=	kvirc
INSTALLS_SHLIB=	yes
MAN1=		kvirc.1
USE_LIBTOOL=	yes
USE_AUTOMAKE=	yes
USE_AUTOCONF=	yes
USE_QT_VER=	2
USE_X_PREFIX=	yes
USE_GMAKE=	yes
QT_NONSTANDARD=	yes
CONFIGURE_ARGS=	--x-includes=$(X11BASE)/include \
		--x-libraries=$(X11BASE)/lib \
		--datadir=$(PREFIX)/share \
		--with-qt-moc=${X11BASE}/bin/moc2 \
		--with-qt-include-dir=${X11BASE}/include/qt2 \
		--with-qt-library-dir=${X11BASE}/lib \
		--without-kde-check \
		--with-freebsd-pthread \
		--with-qt-name=qt2 \
		--disable-static

CONFIGURE_ENV+=	SS_X_EXTRA_LIBS=-lxpg4

.include <bsd.port.mk>
