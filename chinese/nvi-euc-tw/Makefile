# New ports collection makefile for:	nvi-1.79 + multilingual patch(euc-tw)
# Date created:		5 Apr 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

CATEGORIES=	chinese editors
PKGNAMESUFFIX=	-euctw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of vi/ex, with multilingual patch, default settings for euc-tw

CONFIGURE_ARGS+=	--enable-multibyte=euc-tw --program-prefix=n

MASTERDIR=	${.CURDIR}/../../editors/nvi-m17n

.include "${MASTERDIR}/Makefile"
