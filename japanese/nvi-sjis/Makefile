# New ports collection makefile for:	nvi-1.79 + multilingual patch(sjis)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.5 1997/04/09 09:43:53 asami Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../editors/nvi/files
PATCHDIR=	${.CURDIR}/../../editors/nvi/patches
PKGDIR=		${.CURDIR}/../../editors/nvi/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

LIB_DEPENDS=	canna\\.1\\.:${PORTSDIR}/japanese/Canna

.include <${.CURDIR}/../../editors/nvi/Makefile>

PKGNAME=	jp-nvi-sjis-1.79-970617
CATEGORIES=	japanese editors

MAINTAINER=	itojun@itojun.org

CONFIGURE_ARGS=	--enable-multibyte=sjis --program-prefix=n --enable-canna
