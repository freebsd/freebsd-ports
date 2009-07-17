# ex:ts=8
# Ports collection makefile for:  postmark
# Date created:			  Sat Sep 18, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	postmark
PORTVERSION=	1.51
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

PATCH_SITES=	${MASTER_SITE_DEBIAN_POOL}
PATCHFILES=	${PORTNAME}_${PORTVERSION}-5.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NetApps file system benchmark

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	sbin/postmark

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o postmark postmark-${PORTVERSION}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/postmark ${PREFIX}/sbin

.include <bsd.port.mk>
