# New ports collection makefile for:	nvi-1.79 + multilingual patch(big5)
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

CATEGORIES=	chinese editors
PKGNAMESUFFIX=	-big5

MASTERDIR=	${.CURDIR}/../../editors/nvi-m17n

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of vi/ex, with multilingual patch, default settings for big5

CONFIGURE_ARGS+=	--enable-multibyte=big5 --program-prefix=n

.include "${MASTERDIR}/Makefile"
