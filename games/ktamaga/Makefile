# New ports collection makefile for:   ktamaga
# Version required:    0.2
# Date created:        13 November 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.9 1998/10/02 18:21:31 brian Exp $
#

DISTNAME=	ktamaga-0.2
CATEGORIES=	games kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/unstable/apps/games/ \
		ftp://ftp.kde.org/pub/kde/unstable/apps/games/

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs
MAKE_ENV=	DEBUG_FL="$(CFLAGS)"

USE_QT=		yes
WRKSRC=		${WRKDIR}/tamaga-0.2

.include <bsd.port.mk>
