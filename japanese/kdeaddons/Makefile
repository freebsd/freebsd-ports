# New ports collection makefile for:	Japanized addons for kde
# Date created:		28 August 2001
# Whom:			SASAKI Katuhiro <sahiro@crest.ocn.ne.jp>
#
# $FreeBSD$
#

# This port does not work with another version of master port.
#PORTVERSION=	2.2.1
CATEGORIES=	japanese misc kde

MASTERDIR=	${.CURDIR}/../../misc/kdeaddons
MD5_FILE=	${.CURDIR}/distinfo

MAINTAINER=	sahiro@crest.ocn.ne.jp

PATCH_SITES=	http://www.kde.gr.jp/patch/
PATCHFILES=	kdeaddons-2.2.1-babelfish-ja-20010922.diff
PATCH_DIST_STRIP=	-p1

LIB_DEPENDS=	konq.4:${PORTSDIR}/japanese/kdebase2

.include "${MASTERDIR}/Makefile"
