# New ports collection makefile for:	nvi-1.79 + multilingual patch(sjis)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.7 1997/08/21 16:55:27 itojun Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../editors/nvi/files
PATCHDIR=	${.CURDIR}/../../editors/nvi/patches
PKGDIR=		${.CURDIR}/../../editors/nvi/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

LIB_DEPENDS=	canna\\.1\\.:${PORTSDIR}/japanese/Canna

.include <${.CURDIR}/../../editors/nvi/Makefile>

PKGNAME=	ja-nvi-sjis-1.79-970820
CATEGORIES=	japanese editors

MAINTAINER=	itojun@itojun.org

CONFIGURE_ARGS=	--enable-multibyte=sjis --program-prefix=n --enable-canna
