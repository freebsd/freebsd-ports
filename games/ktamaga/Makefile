# New ports collection makefile for:   ktamaga
# Version required:    0.2
# Date created:        13 November 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id:$
#

DISTNAME=	ktamaga-0.2
CATEGORIES=	games kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/pub/kde/old/apps/games/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/old/apps/games/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/old/apps/games/

MAINTAINER=	se@freebsd.org

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11/qt \
		kdecore\\.0\\.1[1-9]:${PORTSDIR}/x11/kdelibs

WRKSRC=		${WRKDIR}/tamaga-0.2

.include <bsd.port.mk>
