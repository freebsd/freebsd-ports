# New ports collection makefile for:	bind
# Date created:		18 July 1997
# Whom:			jseger@scds.com
#
# $FreeBSD$
#

CATEGORIES=	chinese net

MASTERDIR=	${.CURDIR}/../../dns/bind8

PATCH_SITES=	http://www.sinica.edu.tw/~jihuang/

DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
PATCHFILES=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}.diff.gz

.include "${MASTERDIR}/Makefile"

MD5_FILE=	${.CURDIR}/distinfo
PKGNAMEPREFIX:= ${PKGNAMEPREFIX}

MAINTAINER=	jihuang@gate.sinica.edu.tw
