# New ports collection makefile for:	dictd
# Date created:			19 July 2002
# Whom:				Kuang-che Wu <kcwu@ck.tp.edu.tw>
#
# $FreeBSD$
#

CATEGORIES=	chinese

MAINTAINER=	kcwu@ck.tp.edu.tw

MASTERDIR=	${.CURDIR}/../../net/dictd
EXTRA_PATCHES=	${.CURDIR}/files/patch-index.c \
		${.CURDIR}/files/patch-libmaa::arg.c

.include "${MASTERDIR}/Makefile"

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}tw-
