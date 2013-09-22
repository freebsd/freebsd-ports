# Created by: Alexander Langer <alex@big.endian.de>
# $FreeBSD$

PORTNAME=	ispell
CATEGORIES=	german
PKGNAMESUFFIX=	-neu-20071211

MAINTAINER=	office@FreeBSD.org

ISPELL_DENEU=	yes
MASTERDIR=	${.CURDIR}/../../textproc/ispell
USES=		perl5
NO_STAGE=	yes

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include        "${MASTERDIR}/Makefile"
