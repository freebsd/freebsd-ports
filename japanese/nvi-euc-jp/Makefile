# New ports collection makefile for:	nvi-1.79 + multilingual patch(euc-jp)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.2 1997/03/15 11:56:01 asami Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../editors/nvi/files
PATCHDIR=	${.CURDIR}/../../editors/nvi/patches
PKGDIR=		${.CURDIR}/../../editors/nvi/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

.include <${.CURDIR}/../../editors/nvi/Makefile>

PKGNAME=	jp-nvi-eucjp-1.79-970403
CATEGORIES=	japanese editors

MAINTAINER=	itojun@itojun.org

LIB_DEPENDS+=	canna\\.1\\.:${PORTSDIR}/japanese/Canna

CONFIGURE_ARGS=	--enable-multibyte=euc-jp --program-prefix=n --enable-canna
