# New ports collection makefile for:	nvi-1.79 + multilingual patch(euc-jp)
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-eucjp

MASTERDIR=	${.CURDIR}/../../editors/nvi-m17n

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna

CATEGORIES=	japanese editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of vi/ex, with multilingual patch, default settings for euc-jp

CONFIGURE_ARGS=	--enable-multibyte=euc-jp --program-prefix=n --enable-canna

.include       "${MASTERDIR}/Makefile"
