# New ports collection makefile for:	nvi-1.79 + multilingual patch(euc-cn)
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

CATEGORIES=	chinese editors
PKGNAMESUFFIX=	-euccn

MAINTAINER=	ports@freebsd.org

PORTCOMMENT=	A clone of vi/ex, with multilingual patch, default settings for euc-cn

CONFIGURE_ARGS+=	--enable-multibyte=euc-cn --program-prefix=n

MASTERDIR=	${.CURDIR}/../../editors/nvi-m17n
COMMENT=	${.CURDIR}/pkg-comment

.include "${MASTERDIR}/Makefile"
