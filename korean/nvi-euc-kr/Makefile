# New ports collection makefile for:	nvi-1.79 + multilingual patch(euc-kr)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.6 1997/08/21 16:55:28 itojun Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../editors/nvi/files
PATCHDIR=	${.CURDIR}/../../editors/nvi/patches
PKGDIR=		${.CURDIR}/../../editors/nvi/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

.include <${.CURDIR}/../../editors/nvi/Makefile>

PKGNAME=	ko-nvi-euckr-1.79-970820
CATEGORIES=	korean editors

MAINTAINER=	itojun@itojun.org

CONFIGURE_ARGS=	--enable-multibyte=euc-kr --program-prefix=n
