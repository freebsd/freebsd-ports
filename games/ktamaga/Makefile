# New ports collection makefile for:   ktamaga
# Version required:    0.2
# Date created:        13 November 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.4 1998/04/29 17:51:20 asami Exp $
#

DISTNAME=	ktamaga-0.2
CATEGORIES=	games kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/unstable/apps/games/ \
		ftp://ftp.kde.org/pub/kde/unstable/apps/games/

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11-toolkits/qt
LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11-toolkits/qt \
		kdecore\\.0\\.1[1-9]:${PORTSDIR}/x11/kdelibs

BROKEN=		upgrade

WRKSRC=		${WRKDIR}/tamaga-0.2

.include <bsd.port.mk>
