# New ports collection makefile for:	kvirc
# Date created:		Mon Feb 15 02:53:29 CET 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	kvirc
PORTVERSION=	2.0.0
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.kvirc.bz.nu/pub/mirror/kvirc/2.0.0/source/ \
		ftp://kvirc.firenze.linux.it/pub/kvirc/2.0.0/source/

MAINTAINER=	trevor@FreeBSD.org

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext

ALL_TARGET=	kvirc
MAN1=		kvirc.1
USE_LIBTOOL=	yes
USE_AUTOMAKE=	yes
USE_AUTOCONF=	yes
USE_NEWGCC=	yes
USE_QT2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--x-includes=$(X11BASE)/include \
		--x-libraries=$(X11BASE)/lib \
		--datadir=$(PREFIX)/share \
		--with-qt-moc=${X11BASE}/bin/moc2 \
		--with-qt-include-dir=${X11BASE}/include/qt2 \
		--with-qt-library-dir=${X11BASE}/lib \
		--without-kde-check \
		--without-pthread-check \
		--without-qt-check \
		--without-plugin-support
CONFIGURE_ENV+=	SS_X_EXTRA_LIBS=-lxpg4

pre-build:
	for i in `find ${WRKSRC} -name Makefile` ; do \
		${PERL} -pi -e "s@lqt @lqt2 @g" $$i ; \
		${PERL} -pi -e "s@lpthread@pthread@g" $$i ; \
	done

.include <bsd.port.mk>
