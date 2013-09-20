# Created by: Alexander Langer <alex@big.endian.de>
# $FreeBSD$

PORTNAME=	ispell
CATEGORIES=	german
PKGNAMESUFFIX=	-alt-19991219

MAINTAINER=	office@FreeBSD.org

ISPELL_DEALT=	yes
MASTERDIR=	${.CURDIR}/../../textproc/ispell

.if exists(${.CURDIR}/Makefile.local)
NO_STAGE=	yes
.include "${.CURDIR}/Makefile.local"
.endif

.include        "${MASTERDIR}/Makefile"
