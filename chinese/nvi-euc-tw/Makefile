# New ports collection makefile for:	nvi-1.79 + multilingual patch(euc-tw)
# Version required:	1.79
# Date created:		5 Apr 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.9 1998/03/04 19:35:04 asami Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../editors/nvi-m17n/files
PATCHDIR=	${.CURDIR}/../../editors/nvi-m17n/patches
PKGDIR=		${.CURDIR}/../../editors/nvi-m17n/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

PKGNAME=	zh-nvi-euctw-1.79.19970820

.include <${.CURDIR}/../../editors/nvi-m17n/Makefile>

CATEGORIES=	chinese editors

MAINTAINER=	itojun@itojun.org

CONFIGURE_ARGS+=	--enable-multibyte=euc-tw --program-prefix=n
