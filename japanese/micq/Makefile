# New ports collection makefile for:	micq
# Date created:				31 Oct 1998
# Whom:					flathill
#
# $FreeBSD$
#

PORTNAME=	micq
PORTVERSION=	0.4.3
CATEGORIES=	japanese net
MASTER_SITES=	ftp://micq.chatzone.org/pub/micq/V0.4.3/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flathill
EXTRACT_SUFX=	.tgz

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	flathill
PATCHFILES=	${DISTNAME}-jp.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	flathill@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/micq
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/micq
.endif

.include <bsd.port.mk>
