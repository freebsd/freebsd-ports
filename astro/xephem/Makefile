# New ports collection makefile for:    xephem
# Version required:     3.1
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.5 1997/03/27 23:44:44 erich Exp $
#

DISTNAME=	xephem-3.1
CATEGORIES=	astro
MASTER_SITES=	ftp://iraf.noao.edu/contrib/xephem/xephem-3.1/ \
		ftp://gastro23.physics.uiowa.edu/pub/xephem/ \
		ftp://iphcip1.physik.uni-mainz.de/pub/xephem/ \
		ftp://wolf.ifj.edu.pl/mirror/xephem/

MAINTAINER=	erich@FreeBSD.org

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem

LIBSRC=		${WRKDIR}/${DISTNAME}/libastro

pre-configure:
	@(cd ${LIBSRC} && ${XMKMF})

pre-build:
	@(cd ${LIBSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

.include <bsd.port.mk>
