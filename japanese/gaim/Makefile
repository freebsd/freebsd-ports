# New ports collection makefile for:	ja-gaim
# Date created:        13 October 2003
# Whom:                Takahiro Morishita <morishita@skywing.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese net

PATCH_SITES=		http://www.cc.rim.or.jp/~yaz/:jp_patch
PATCHFILES=		gaim-0.74_jp.patch.gz:jp_patch
PATCH_DIST_STRIP=	-p1:jp_patch

MAINTAINER=	morishita@skywing.org

MASTERDIR=	${.CURDIR}/../../net/gaim
MD5_FILE=	${.CURDIR}/distinfo

BROKEN=		"Japanese patch not yet released"

CONFLICTS=	gaim-*

.include "${MASTERDIR}/Makefile"
