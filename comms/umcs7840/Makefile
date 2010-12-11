# New ports collection makefile for:	umcs7840
# Date created:				09 Nov 2010
# Whom:					Lev Serebryakov <lev@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	umcs7840
PORTVERSION=	${MAINVERSION}.${VERSIONDATE}
CATEGORIES=	comms kld
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/umcs7840/
PKGNAMESUFFIX=	-kmod

MAINTAINER=	lev@FreeBSD.org
COMMENT=	MosChip MCS7820 and MCS7840 USB to RS-232/485 gates driver

USE_BZIP2=	yes

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

MAINVERSION=1.0
VERSIONDATE=20101210.57

KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR=${KMODDIR}

MANCOMPRESSED=	yes
MAN4=		${PORTNAME}.4

.include <bsd.port.pre.mk>

.if !exists(/usr/src/sys/Makefile)
IGNORE=	requires kernel source files
.elif ${OSVERSION} <= 800063
IGNORE=	requires FreeBSD 8.0 or later, please try driver from vendor site
.endif

post-install:
	kldxref ${KMODDIR}

post-deinstall:
	kldxref ${KMODDIR}

.include <bsd.port.post.mk>
