# New ports collection makefile for:	plasma-kmod
# Date created:				24 January 2001
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	plasma
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	graphics kld
MASTER_SITES=	SF/futurebsd/futurebsd/${PORTNAME}
PKGNAMESUFFIX=	-kmod

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A plasma-effect screensaver kernel module

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/dev/syscons/syscons.h)
IGNORE=		requires kernel source (in ${SRC_BASE}) to build
.endif
PLIST_FILES=	lib/plasma_saver.ko
SUB_FILES=	pkg-message

do-install:
	${INSTALL_KLD} ${WRKSRC}/plasma_saver.ko ${PREFIX}/lib

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
