# New ports collection makefile for:	Japanized kdebase2
# Date created:		28 August 2001
# Whom:			SASAKI Katuhiro <sahiro@crest.ocn.ne.jp>
#
# $FreeBSD$
#

# This port does not work with another version of master port.
#PORTVERSION=	2.2.1
CATEGORIES=	japanese x11 kde

MASTERDIR=	${.CURDIR}/../../x11/kdebase2
MD5_FILE=	${.CURDIR}/distinfo

MAINTAINER=	sahiro@crest.ocn.ne.jp

PATCH_SITES=	http://www.kde.gr.jp/patch/
PATCHFILES=	kdebase-2.2.1-konsole-ja-20010922.diff \
		kdebase-2.2.1-kpersonalizer-charset-20010922.diff
PATCH_DIST_STRIP=	-p1

.include "${MASTERDIR}/Makefile"
