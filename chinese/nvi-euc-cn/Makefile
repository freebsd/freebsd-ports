# New ports collection makefile for:	nvi-1.79 + multilingual patch(euc-cn)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.13 1998/11/19 04:46:43 itojun Exp $
#

PKGNAME=	zh-nvi-euccn-1.79.19981119

MASTERDIR=	${.CURDIR}/../../editors/nvi-m17n
COMMENT=	${.CURDIR}/pkg/COMMENT

.include "${MASTERDIR}/Makefile"

CATEGORIES=	chinese editors

MAINTAINER=	itojun@itojun.org

CONFIGURE_ARGS+=	--enable-multibyte=euc-cn --program-prefix=n
