# New ports collection makefile for:	nvi-1.79 + multilingual patch(euc-kr)
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-euckr

MASTERDIR=	${.CURDIR}/../../editors/nvi-m17n
COMMENT=	${.CURDIR}/pkg-comment

CATEGORIES=	korean editors

MAINTAINER=	ports@freebsd.org

CONFIGURE_ARGS=        --enable-multibyte=euc-kr --program-prefix=n

.include "${MASTERDIR}/Makefile"
