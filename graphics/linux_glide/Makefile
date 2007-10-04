# New ports collection makefile for:    linux_glide
# Date created:         Oct, 8, 1998
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $FreeBSD$
#
#

PORTNAME=	glide
PORTVERSION=	2.4
PORTREVISION=	2
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
WRKSRC=		${WRKDIR}/Glide2.4

do-build:
	@zcat ${WRKSRC}/dist.tar.gz | \
		(cd ${WRKSRC}; tar fx - lib include bin/test00)

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${PREFIX}/usr)
	(cd ${WRKSRC} && ${COPYTREE_SHARE} include ${PREFIX}/usr)
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} bin/test00 \
		${PREFIX}/usr/bin/test-glide)
	-/compat/linux/sbin/ldconfig

.include <bsd.port.mk>
