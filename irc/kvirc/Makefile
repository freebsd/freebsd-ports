# New ports collection makefile for:	kvirc
# Version required:	0.9.0
# Date created:		Mon Feb 15 02:53:29 CET 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

DISTNAME=	kvirc-0.9.0
CATEGORIES=	irc kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR=	 stable/1.1/apps/network

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		kdeui.2:${PORTSDIR}/x11/kdelibs11 \
		khtmlw.2:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

KDEDIR=		${PREFIX}

CONFIGURE_ARGS=	--x-includes=$(X11BASE)/include --x-libraries=$(X11BASE)/lib \
		--datadir=$(PREFIX)/share/kde
CONFIGURE_ENV=	MOC=${X11BASE}/bin/moc

.include <bsd.port.mk>
