# New ports collection makefile for:	Japanized qt23
# Date created:		28 August 2001
# Whom:			SASAKI Katuhiro <sahiro@crest.ocn.ne.jp>
#
# $FreeBSD$
#

# This port does not work with another version of master port.
#PORTVERSION=	2.3.1
PORTREVISION=	4
CATEGORIES=	japanese x11-toolkits

MASTERDIR=	${.CURDIR}/../../x11-toolkits/qt23
MD5_FILE=	${.CURDIR}/distinfo

MAINTAINER=	sahiro@crest.ocn.ne.jp

PATCH_SITES=	http://www.kde.gr.jp/patch/ \
		http://www7.ocn.ne.jp/~s-sahiro/kde/patches/
PATCHFILES=	qt-2.3.1-qclipboard-20010617.diff \
		qt-2.3.1-qpsprinter-ja-20010620.diff \
		qt-2.3.1-qstring-toDouble-i18n-20010617.diff \
		qt-2.3.1-showFullScreen-fix-20010624.diff \
		qt-2.3.1-xim-20010617.diff \
		qt-2.3.1-qtextcodec-20011222.diff \
		qt-2.3.2-xim-overflow-20020205.diff \
		qt-2.3.1-xicfontset.patch \
		qt-2.3.1-ximbaseline.patch
PATCH_DIST_STRIP=	-p1

.include "${MASTERDIR}/Makefile"
