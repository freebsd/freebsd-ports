# New ports collection makefile for:	nvi-1.79 + multilingual patch(iso-2022-jp)
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-iso2022jp

MASTERDIR=	${.CURDIR}/../../editors/nvi-m17n

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna

CATEGORIES=	japanese editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of vi/ex, with multilingual patch, default settings for iso-2022-jp

CONFIGURE_ARGS=	--enable-multibyte=iso-2022-jp --program-prefix=n --enable-canna

.include       "${MASTERDIR}/Makefile"
