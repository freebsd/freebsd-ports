# New ports collection makefile for:	Japanized kdevelop
# Date created:		28 August 2001
# Whom:			SASAKI Katuhiro <sahiro@crest.ocn.ne.jp>
#
# $FreeBSD$
#

# This port does not work with another version of master port.
#PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	japanese devel kde

MASTERDIR=	${.CURDIR}/../../devel/kdevelop
MD5_FILE=	${.CURDIR}/distinfo

MAINTAINER=	sahiro@crest.ocn.ne.jp

BROKEN=		"Broken by master port update"

PATCH_SITES=	http://www.kde.gr.jp/patch/ \
		http://www7.ocn.ne.jp/~s-sahiro/kde/patches/
PATCHFILES=	kdevelop-2.0.2-font-i18n-20011127.diff \
		kdevelop-2.0.2-i18n-20020204.diff
PATCH_DIST_STRIP=	-p1

.include "${MASTERDIR}/Makefile"
