# Created by: Shen Chuan-Hsing <statue@mail.elife.idv.tw>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	chinese

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	chinsan/patch
PATCHFILES=	zh-joe-3.7.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

LATEST_LINK=	${PKGNAMEPREFIX}joe

MASTERDIR=	${.CURDIR}/../../editors/joe
DISTINFO_FILE=	${.CURDIR}/distinfo

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
