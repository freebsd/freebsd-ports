# New ports collection makefile for:   krio
# Version required:    19990721
# Date created:        22 Sep 1999
# Whom:                ak@freenet.co.uk
#
# $FreeBSD$
#

DISTNAME=	Krio-19990721
PKGNAME=	krio-19990721
CATEGORIES=	audio kde
MASTER_SITES=	ftp://ftp.13th-floor.org/pub/krio/

MAINTAINER=	ak@freenet.co.uk

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		kdeui.3:${PORTSDIR}/x11/kdelibs11 \
		kfm.3:${PORTSDIR}/x11/kdelibs11 \
		kfile.3:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes

WRKSRC=		${WRKDIR}/Krio

do-install:
		${MKDIR} ${PREFIX}/share/icons/mini ${PREFIX}/share/applnk/Utilities
		${INSTALL_PROGRAM} ${WRKSRC}/krio ${PREFIX}/bin/krio
		${INSTALL_DATA} ${WRKSRC}/icons/krio.xpm ${PREFIX}/share/icons/krio.xpm
		${INSTALL_DATA} ${WRKSRC}/icons/mini/mini-krio.xpm ${PREFIX}/share/icons/mini/krio.xpm
		${INSTALL_DATA} ${WRKSRC}/Krio.kdelnk ${PREFIX}/share/applnk/Utilities/krio.kdelnk

.include <bsd.port.mk>
