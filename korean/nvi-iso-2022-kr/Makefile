# New ports collection makefile for:	nvi-1.79 + multilingual patch(iso-2022-kr)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id$
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
.include <${.CURDIR}/../../editors/nvi/Makefile>
# bsd.port.mk has been included in the above statement, so we don't need to
# include it again.

PKGNAME=	kr-nvi-iso2022kr-1.79-970306
CATEGORIES=	korean editors

MAINTAINER=	itojun@itojun.org

#LIB_DEPENDS+=	canna\\.1\\.:${PORTSDIR}/japanese/Canna

FILESDIR=	${PORTSDIR}/editors/nvi/files
PATCHDIR=	${PORTSDIR}/editors/nvi/patches
PKGDIR=		${PORTSDIR}/editors/nvi/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

CONFIGURE_ARGS=	--enable-multibyte=iso-2022-kr --program-prefix=n
