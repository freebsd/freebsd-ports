# New ports collection makefile for:	nvi-1.79 + multilingual patch(euc-jp)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.9 1998/02/17 13:11:52 itojun Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../editors/nvi/files
PATCHDIR=	${.CURDIR}/../../editors/nvi/patches
PKGDIR=		${.CURDIR}/../../editors/nvi/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

LIB_DEPENDS=	canna\\.1\\.:${PORTSDIR}/japanese/Canna

PKGNAME=	ja-nvi-eucjp-1.79.19970820

.include <${.CURDIR}/../../editors/nvi-m17n/Makefile>

CATEGORIES=	japanese editors

MAINTAINER=	itojun@itojun.org

CONFIGURE_ARGS=	--enable-multibyte=euc-jp --program-prefix=n --enable-canna
