# New ports collection makefile for:    linux_glide
# Date created:         Oct, 8, 1998
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $FreeBSD$
#
#

PORTNAME=	glide
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	http://www2.cons.org/freebsd-distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cracauer
PKGNAMEPREFIX=	linux_
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_2_4

MAINTAINER=	cracauer@cons.org
COMMENT=	Linux library implementing the GLIDE interface to 3dfx video cards

ONLY_FOR_ARCHS=	i386

USE_LINUX_PREFIX=yes
USE_LINUX=	yes
NO_MTREE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Glide2.4

do-install:
	@zcat ${WRKSRC}/dist.tar.gz | \
		(cd ${PREFIX}/usr; tar fx - lib include bin/test00)
	${MV} ${PREFIX}/usr/bin/test00 ${PREFIX}/usr/bin/test-glide

post-install:
	-/compat/linux/sbin/ldconfig

.include <bsd.port.mk>
