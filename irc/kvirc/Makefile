# New ports collection makefile for:	kvirc
# Version required:	1.0.0
# Date created:		Mon Feb 15 02:53:29 CET 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

DISTNAME=	kvirc-1.0.0
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.kvirc.bz.nu/pub/mirror/kvirc/ \
		http://www.kvirc.org/

MAINTAINER=	will@FreeBSD.org

USE_QT2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--x-includes=$(X11BASE)/include --x-libraries=$(X11BASE)/lib \
		--datadir=$(PREFIX)/share --with-qt-moc=${X11BASE}/bin/moc2 \
		--with-qt-include-dir=${X11BASE}/include/qt2 \
		--with-qt-library-dir=${X11BASE}/lib
USE_LIBTOOL=	yes

.include <bsd.port.mk>
