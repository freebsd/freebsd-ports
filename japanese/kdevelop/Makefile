# New ports collection makefile for:	Japanized kdevelop
# Date created:		28 August 2001
# Whom:			SASAKI Katuhiro <sahiro@crest.ocn.ne.jp>
#
# $FreeBSD$
#

# This port does not work with another version of master port.
#PORTVERSION=	2.0.1
CATEGORIES=	japanese devel kde

MASTERDIR=	${.CURDIR}/../../devel/kdevelop
MD5_FILE=	${.CURDIR}/distinfo

MAINTAINER=	sahiro@crest.ocn.ne.jp

PATCH_SITES=	http://www.kde.gr.jp/patch/
PATCHFILES=	kdevelop-2.0.1-font-i18n-20010922.diff \
		kdevelop-2.0.1-i18n-20010922.diff
PATCH_DIST_STRIP=	-p1

.include "${MASTERDIR}/Makefile"
