# New ports collection makefile for:	Japanized kdenetwork2
# Date created:		28 August 2001
# Whom:			SASAKI Katuhiro <sahiro@crest.ocn.ne.jp>
#
# $FreeBSD$
#

# This port does not work with another version of master port.
#PORTVERSION=	2.2.1
CATEGORIES=	japanese net news kde

MASTERDIR=	${.CURDIR}/../../net/kdenetwork2
MD5_FILE=	${.CURDIR}/distinfo

MAINTAINER=	sahiro@crest.ocn.ne.jp

PATCH_SITES=	http://www.kde.gr.jp/patch/
PATCHFILES=	kdenetwork-2.2.1-kmail-honyaku-20010922.diff \
		kdenetwork-2.2.1-kmail-unknownchrset-cjk-20010922.diff \
		kdenetwork-2.2.1-kmail-show_userAgent-20010922.diff \
		kdenetwork-2.2.1-knewsticker-utf8-20010922.diff \
		kdenetwork-2.2.1-ksirc-ja-20010922.diff
PATCH_DIST_STRIP=	-p1

.include "${MASTERDIR}/Makefile"
