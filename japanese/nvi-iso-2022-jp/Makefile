# New ports collection makefile for:	nvi-1.79 + multilingual patch(iso-2022-jp)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.3 1997/04/09 07:10:05 asami Exp $
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../editors/nvi/files
PATCHDIR=	${.CURDIR}/../../editors/nvi/patches
PKGDIR=		${.CURDIR}/../../editors/nvi/pkg
COMMENT=	${.CURDIR}/pkg/COMMENT

.include <${.CURDIR}/../../editors/nvi/Makefile>

PKGNAME=	jp-nvi-iso2022jp-1.79-970408
CATEGORIES=	japanese editors

MAINTAINER=	itojun@itojun.org

LIB_DEPENDS+=	canna\\.1\\.:${PORTSDIR}/japanese/Canna

CONFIGURE_ARGS=	--enable-multibyte=iso-2022-jp --program-prefix=n --enable-canna
