# New ports collection makefile for:   ktamaga
# Version required:    0.2
# Date created:        13 November 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.2 1997/12/03 00:39:43 se Exp $
#

DISTNAME=	ktamaga-0.2
CATEGORIES=	games kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/unstable/apps/games/ \
		ftp://ftp.kde.org/pub/kde/unstable/apps/games/

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11/qt \
		kdecore\\.0\\.1[1-9]:${PORTSDIR}/x11/kdelibs

WRKSRC=		${WRKDIR}/tamaga-0.2

.include <bsd.port.mk>
