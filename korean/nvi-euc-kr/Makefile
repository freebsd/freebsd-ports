# New ports collection makefile for:	nvi-1.79 + multilingual patch(euc-kr)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PKGNAME=	ko-nvi-euckr-1.79.19990331

MASTERDIR=	${.CURDIR}/../../editors/nvi-m17n
COMMENT=	${.CURDIR}/pkg/COMMENT

.include "${MASTERDIR}/Makefile"

CATEGORIES=	korean editors

MAINTAINER=	itojun@itojun.org

CONFIGURE_ARGS+=	--enable-multibyte=euc-kr --program-prefix=n
