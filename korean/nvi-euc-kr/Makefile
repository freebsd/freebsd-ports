# New ports collection makefile for:	nvi-1.79 + multilingual patch(euc-kr)
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-euckr

MASTERDIR=	${.CURDIR}/../../editors/nvi-m17n

CATEGORIES=	korean editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of vi/ex, with multilingual patch, default settings for euc-kr

CONFIGURE_ARGS=	--enable-multibyte=euc-kr --program-prefix=n

.include "${MASTERDIR}/Makefile"
