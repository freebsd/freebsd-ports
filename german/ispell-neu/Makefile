# New ports collection makefile for:    deneu-ispell
# Date created:                         10 February 2000
# Whom:                                 Alexander Langer <alex@big.endian.de>
#
# $FreeBSD$
#

PORTNAME=	ispell
CATEGORIES=	german
PKGNAMESUFFIX=	-neu-20001109

MAINTAINER=	alex@FreeBSD.org

ISPELL_DENEU=	yes
MASTERDIR=	${.CURDIR}/../../textproc/ispell
USE_PERL5=	yes

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include        "${MASTERDIR}/Makefile"
