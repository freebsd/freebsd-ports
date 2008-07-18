# New ports collection makefile for:	unzoo
# Date created:				20 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	unzoo
PORTVERSION=	4.4
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	unzoo_4.4-4.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A zoo archive extractor

EXTRA_DEFINES=	-DSYS_IS_UNIX -DSYS_HAS_MKDIR

MAN1=		unzoo.1
PLIST_FILES=	bin/unzoo

CFLAGS+=	-trigraphs

post-extract:
	@${MKDIR} ${WRKSRC}
	@${MV} ${WRKDIR}/${PORTNAME}.c ${WRKSRC}

do-build:
	${CC} ${CFLAGS} ${EXTRA_DEFINES} -o ${WRKSRC}/${PORTNAME} \
		${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/debian/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
