# New ports collection makefile for:	nvi-1.79 + multilingual patch(big5)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.10 1998/03/04 19:35:01 asami Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../editors/nvi-m17n/files
PATCHDIR=	${.CURDIR}/../../editors/nvi-m17n/patches
PKGDIR=		${.CURDIR}/../../editors/nvi-m17n/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

PKGNAME=	zh-nvi-big5-1.79.19970820

.include <${.CURDIR}/../../editors/nvi-m17n/Makefile>

CATEGORIES=	chinese editors

MAINTAINER=	itojun@itojun.org

CONFIGURE_ARGS+=	--enable-multibyte=big5 --program-prefix=n
