# New ports collection makefile for:	plasma-kmod
# Date created:				24 January 2001
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	plasma
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	graphics kld
MASTER_SITES=	SF/futurebsd/futurebsd/${PORTNAME}
PKGNAMESUFFIX=	-kmod

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A plasma-effect screensaver kernel module

.if !exists(/usr/src/sys/dev/syscons/syscons.h)
IGNORE=		requires kernel source (/usr/src/sys) to build
.endif
PLIST_FILES=	lib/plasma_saver.ko

do-install:
	${INSTALL_KLD} ${WRKSRC}/plasma_saver.ko ${PREFIX}/lib

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64"
BROKEN=		Does not configure
.endif
.endif
.if ${OSVERSION} >= 800000
BROKEN=		Does not build
.endif

.include <bsd.port.post.mk>
