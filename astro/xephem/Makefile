# New ports collection makefile for:    xephem
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xephem
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://www.clearskyinstitute.com/xephem/ \
		ftp://iraf.noao.edu/contrib/xephem/ \
		ftp://wolf.ifj.edu.pl/mirror/xephem/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem

USE_MOTIF=	yes
USE_IMAKE=	yes
MAN1=		xephem.1

LIBSRC=		${WRKDIR}/${DISTNAME}/libastro

pre-configure:
	@(cd ${LIBSRC} && ${SETENV} ${MAKE_ENV} ${XMKMF})

pre-build:
	@(cd ${LIBSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})
	@${ECHO} 'XEphem.ShareDir: ${PREFIX}/lib/X11/xephem' > ${WRKSRC}/XEphem.ad

post-install:
	${INSTALL_DATA} ${WRKSRC}/XEphem.ad ${PREFIX}/lib/X11/app-defaults/XEphem
	@${MKDIR} ${PREFIX}/lib/X11/xephem
	${TAR} -C ${WRKSRC} -cf - auxil catalogs fits fifos tools \
		| ${TAR} -C ${PREFIX}/lib/X11/xephem --unlink -xf -
	@find ${PREFIX}/lib/X11/xephem | xargs ${CHOWN} ${SHAREOWN}:${SHAREMODE}
	@find ${PREFIX}/lib/X11/xephem -type f | xargs ${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
