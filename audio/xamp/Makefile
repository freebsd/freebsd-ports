# New ports collection makefile for:	xamp
# Version required:		0.8-7
# Date created:			29 July 1998
# Whom:				Joe Jih-Shian Lu <jslu@dns.ntu.edu.tw>
#
# $Id: Makefile,v 1.2 1998/08/25 03:48:00 vanilla Exp $
#

DISTNAME=	xamp-0.8-7
PKGNAME=	xamp-0.8.7
CATEGORIES=	audio
MASTER_SITES=	http://elan.rulez.org/~xopy/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jslu@dns.ntu.edu.tw

USE_QT=		yes

WRKSRC=		${WRKDIR}/xamp-0.8/xamp-0.8
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"
USE_GMAKE=	yes
USE_X_PREFIX=	yes

MAN1=		xamp.1

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/xamp ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/xamp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
