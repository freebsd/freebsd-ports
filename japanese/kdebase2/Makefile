# New ports collection makefile for:	Japanized kdebase2
# Date created:		28 August 2001
# Whom:			SASAKI Katuhiro <sahiro@crest.ocn.ne.jp>
#
# $FreeBSD$
#

# This port does not work with another version of master port.
#PORTVERSION=	2.2.2
PORTREVISION=	5
CATEGORIES=	japanese x11 kde

MASTERDIR=	${.CURDIR}/../../x11/kdebase2
MD5_FILE=	${.CURDIR}/distinfo

MAINTAINER=	sahiro@crest.ocn.ne.jp

PATCH_SITES=	http://www.kde.gr.jp/patch/ \
		http://www7.ocn.ne.jp/~s-sahiro/kde/patches/
PATCHFILES=	kdebase-2.2.2-konsole-ja-20011126.diff \
		kdebase-2.2.2-kpersonalizer-charset-20011126.diff \
		kdebase-2.2.2-kcontrol-defaultfonts.patch \
		kdebase-2.2.2-kpager-defaultfonts.patch \
		kdebase-2.2.2-kwin-defaultfonts.patch
PATCH_DIST_STRIP=	-p1

.include "${MASTERDIR}/Makefile"
