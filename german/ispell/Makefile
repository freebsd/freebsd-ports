# Created by: Alexander Langer <alex@big.endian.de>
# $FreeBSD$

PORTNAME=	ispell
CATEGORIES=	german
PKGNAMESUFFIX=	-20071211

MAINTAINER=	office@FreeBSD.org

USES=		perl5

ISPELL_DEALT=	yes
ISPELL_DENEU=	yes
MASTERDIR=	${.CURDIR}/../../textproc/ispell
NO_STAGE=	yes

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include        "${MASTERDIR}/Makefile"
