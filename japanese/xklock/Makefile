# New ports collection makefile for:	xklock
# Date created:		20 April 1997
# Whom:			nkazushi@highway.or.jp
#
# $FreeBSD$
#

PORTNAME=	xklock
PORTVERSION=	2.7.1
CATEGORIES=	japanese x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}+lx.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

pre-configure:
	@${MV} ${WRKDIR}/jnames.c ${WRKDIR}/jnames.c.in
	@${SED} -e "s:/usr/local:${PREFIX}:" ${WRKDIR}/jnames.c.in  \
		> ${WRKDIR}/jnames.c
	@${MV} ${WRKDIR}/xklock.h ${WRKDIR}/xklock.h.in
	@${SED} -e "s:/usr/local:${PREFIX}:" ${WRKDIR}/xklock.h.in  \
		> ${WRKDIR}/xklock.h

post-install:
	${TOUCH} ${PREFIX}/lib/jnames

.include <bsd.port.mk>
