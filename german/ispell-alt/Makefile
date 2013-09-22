# Created by: Alexander Langer <alex@big.endian.de>
# $FreeBSD$

PORTNAME=	ispell
CATEGORIES=	german
PKGNAMESUFFIX=	-alt-19991219

MAINTAINER=	office@FreeBSD.org

ISPELL_DEALT=	yes
MASTERDIR=	${.CURDIR}/../../textproc/ispell
NO_STAGE=	yes

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include        "${MASTERDIR}/Makefile"
