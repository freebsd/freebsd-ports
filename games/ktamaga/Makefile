# New ports collection makefile for:   ktamaga
# Version required:    0.2
# Date created:        13 November 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.6 1998/08/12 06:29:27 asami Exp $
#

DISTNAME=	ktamaga-0.2
CATEGORIES=	games kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/unstable/apps/games/ \
		ftp://ftp.kde.org/pub/kde/unstable/apps/games/

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	kdecore\\.1\\.:${PORTSDIR}/x11/kdelibs

BROKEN=		upgrade

USE_QT=		yes
WRKSRC=		${WRKDIR}/tamaga-0.2

.include <bsd.port.mk>
