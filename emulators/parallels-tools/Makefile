# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	parallels-tools
PORTVERSION=	0.1.1
CATEGORIES=	emulators kld
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bland

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Parallels Desktop Tools for FreeBSD

SSP_UNSAFE=	kernel module does not support ssp
USE_BZIP2=	yes

ONLY_FOR_ARCHS=	amd64 i386

KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR=${KMODDIR}

.include <bsd.port.mk>
