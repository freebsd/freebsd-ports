# New ports collection makefile for:   angband
# Version required:    2.8.3
# Date created:        21 Feb 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.6 1998/04/17 23:26:22 mph Exp $
#

DISTNAME=	angband-283
PKGNAME=	angband-2.8.3
CATEGORIES=	games
MASTER_SITES=	ftp://export.andrew.cmu.edu/angband/Source/
DISTFILES=	angband-283.tar.gz ext-x11-283.tar.gz

MAINTAINER=	mph@freebsd.org

USE_X_PREFIX=	yes
DIST_SUBDIR=	angband

EXTSRC=		${WRKDIR}/ext-x11-283

pre-patch:
	${CP} ${WRKSRC}/src/Makefile.std ${WRKSRC}/src/Makefile

post-install:
	${INSTALL_DATA} ${EXTSRC}/lib/xtra/tiles.raw \
		${PREFIX}/lib/X11/angband/xtra
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
