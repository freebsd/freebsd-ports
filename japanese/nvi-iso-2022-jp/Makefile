# New ports collection makefile for:	nvi-1.79 + multilingual patch(iso-2022-jp)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.14 1998/11/19 04:46:45 itojun Exp $
#

PKGNAME=	ja-nvi-iso2022jp-1.79.19981119

MASTERDIR=	${.CURDIR}/../../editors/nvi-m17n
COMMENT=	${.CURDIR}/pkg/COMMENT

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna

.include	"${MASTERDIR}/Makefile"

CATEGORIES=	japanese editors

MAINTAINER=	itojun@itojun.org

CONFIGURE_ARGS+=	--enable-multibyte=iso-2022-jp --program-prefix=n --enable-canna
