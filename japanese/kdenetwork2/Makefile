# New ports collection makefile for:	Japanized kdenetwork2
# Date created:		28 August 2001
# Whom:			SASAKI Katuhiro <sahiro@crest.ocn.ne.jp>
#
# $FreeBSD$
#

# This port does not work with another version of master port.
#PORTVERSION=	2.2.2
CATEGORIES=	japanese net news kde

MASTERDIR=	${.CURDIR}/../../net/kdenetwork2
MD5_FILE=	${.CURDIR}/distinfo

MAINTAINER=	sahiro@crest.ocn.ne.jp

PATCH_SITES=	http://www.kde.gr.jp/patch/
PATCHFILES=	kdenetwork-2.2.2-kmail-honyaku-20011126.diff \
		kdenetwork-2.2.2-kmail-unknowncharset-cjk-20011127.diff \
		kdenetwork-2.2.2-kmail-show_userAgent-20011126.diff \
		kdenetwork-2.2.2-knewsticker-utf8-20011127.diff \
		kdenetwork-2.2.2-ksirc-ja-20011127.diff
PATCH_DIST_STRIP=	-p1

.include "${MASTERDIR}/Makefile"
