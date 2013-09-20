# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	plasma
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	graphics kld
MASTER_SITES=	SF/futurebsd/futurebsd/${PORTNAME}
PKGNAMESUFFIX=	-kmod

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A plasma-effect screensaver kernel module

LICENSE=	BSD

SSP_UNSAFE=	kernel module does not support ssp

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/dev/syscons/syscons.h)
IGNORE=		requires kernel source (in ${SRC_BASE}) to build
.endif

KMODDIR=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR:C,^/,,}
MAKE_ARGS=	KMODDIR=${KMODDIR}

.include <bsd.port.post.mk>
