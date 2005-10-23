# New ports collection makefile for:	zh-joe
# Date created:			3 July 1999
# Whom:				Shen Chuan-Hsing <statue@mail.elife.idv.tw>
#
# $FreeBSD$
#

CATEGORIES=	chinese

PATCH_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/joe/
PATCHFILES=	zh-joe-2.8_3-patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

BROKEN=		"Upstream version updated to 2.9.8"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-11-21

LATEST_LINK=	${PKGNAMEPREFIX}joe

MASTERDIR=	${.CURDIR}/../../editors/joe2
MD5_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
