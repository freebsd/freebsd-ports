# New ports collection makefile for:    linux_glide
# Date created:         Oct, 8, 1998
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $FreeBSD$
#
#

PORTNAME=	glide
PORTVERSION=	2.4
CATEGORIES=	graphics linux
MASTER_SITES=	ftp://ftp.3dfx.com/pub/glide/
PKGNAMEPREFIX=	linux_
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_2_4

MAINTAINER=	cracauer@cons.org

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386

PREFIX=		/compat/linux/usr
NO_MTREE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Glide2.4

pre-install:
	@[ -d ${PREFIX} ] || ${MKDIR} ${PREFIX}

do-install:
	@zcat ${WRKSRC}/dist.tar.gz | \
		(cd ${PREFIX}; tar fx - lib include bin/test00)
	${MV} ${PREFIX}/bin/test00 ${PREFIX}/bin/test-glide

post-install:
	-/compat/linux/sbin/ldconfig

.include <bsd.port.mk>
