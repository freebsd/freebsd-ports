# New ports collection makefile for:	nvi-1.79 + multilingual patch(iso-2022-kr)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.7 1997/09/22 16:22:19 max Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../editors/nvi/files
PATCHDIR=	${.CURDIR}/../../editors/nvi/patches
PKGDIR=		${.CURDIR}/../../editors/nvi/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

PKGNAME=	ko-nvi-iso2022kr-1.79.19970820

.include <${.CURDIR}/../../editors/nvi/Makefile>

CATEGORIES=	korean editors

MAINTAINER=	itojun@itojun.org

CONFIGURE_ARGS=	--enable-multibyte=iso-2022-kr --program-prefix=n
