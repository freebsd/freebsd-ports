# New ports collection makefile for:	kvirc
# Date created:		Mon Feb 15 02:53:29 CET 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	kvirc
PORTVERSION=	1.0.0
CATEGORIES=	irc
MASTER_SITES=	http://www.kvirc.org/ \
		ftp://ftp.kvirc.bz.nu/pub/mirror/kvirc/ \
		ftp://kvirc.firenze.linux.it/pub/kvirc/

MAINTAINER=	will@FreeBSD.org

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext \
		qt2.3:${PORTSDIR}/x11-toolkits/qt21

USE_NEWGCC=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--x-includes=$(X11BASE)/include --x-libraries=$(X11BASE)/lib \
		--datadir=$(PREFIX)/share --with-qt-moc=${X11BASE}/bin/moc2 \
		--with-qt-include-dir=${X11BASE}/include/qt2 \
		--with-qt-library-dir=${X11BASE}/lib
CONFIGURE_ENV+=	SS_X_EXTRA_LIBS=-lxpg4
USE_LIBTOOL=	yes

.include <bsd.port.mk>
