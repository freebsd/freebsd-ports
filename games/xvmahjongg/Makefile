# New ports collection makefile for:	xvmahjongg
# Version required:			2.0
# Date created:				21 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/07/27 23:25:33 asami Exp $
#

DISTNAME=	xvmahjongg2.1
PKGNAME=	xvmahjongg-2.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/X11/R5contrib/ \
		ftp://ftp.tu-darmstadt.de/pub/X11/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	xview\\.3\\.2:${PORTSDIR}/x11/xview-lib \
		olgx\\.3\\.2:${PORTSDIR}/x11/xview-lib

ALL_TARGET=	mahjongg.swap
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/mahjongg2.1
MAN6=		xvmahjongg.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/mahjongg ${PREFIX}/bin/xvmahjongg
	@ ${INSTALL_DATA} ${WRKSRC}/mahjongg.6 ${PREFIX}/man/man6/xvmahjongg.6
	@ ${MKDIR} ${PREFIX}/share/doc/xvmahjongg
.for file in Notes README README.too
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xvmahjongg
.endfor

.include <bsd.port.mk>
