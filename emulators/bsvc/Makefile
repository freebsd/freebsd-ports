# New ports collection Makefile for:	bsvc
# Version required:	2.1
# Date created:		03-Mar-1997
# Whom:			tenser@spitfire.ecsel.psu.edu
#
# $FreeBSD$
#

DISTNAME=	bsvc-2.1-src
PKGNAME=	bsvc-2.1
CATEGORIES=	emulators tk82
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/emulators

MAINTAINER=	jseger@FreeBSD.org

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/${PKGNAME}/src

MAKE_ENV=	PROJECT_BASE=${PREFIX} WRKSRC=${WRKSRC}

post-patch:
	${CP} ${WRKSRC}/Makefile.ULTRIX ${WRKSRC}/Makefile

.include <bsd.port.mk>
