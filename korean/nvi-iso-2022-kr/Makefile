# New ports collection makefile for:	nvi-1.79 + multilingual patch(iso-2022-kr)
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-iso2022kr

MASTERDIR=	${.CURDIR}/../../editors/nvi-m17n

CATEGORIES=	korean editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of vi/ex, with multilingual patch, default settings for iso-2022-kr

CONFIGURE_ARGS=	--enable-multibyte=iso-2022-kr --program-prefix=n

.include "${MASTERDIR}/Makefile"
