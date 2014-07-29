# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	parallels-tools
PORTVERSION=	0.1.2
CATEGORIES=	emulators kld
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bland

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Parallels Desktop Tools for FreeBSD

SSP_UNSAFE=	kernel module does not support ssp
USES=	tar:bzip2

ONLY_FOR_ARCHS=	amd64 i386

KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR=${KMODDIR}

PREFIX=		/
MTREE_FILE=	/etc/mtree/BSD.root.dist

.include <bsd.port.mk>
