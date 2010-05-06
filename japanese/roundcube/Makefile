# New ports collection makefile for:	ja-roundcube
# Date created:				2010-02-10
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese mail www

PATCH_SITES=	http://www.sera.desuyo.net/roundcube/
PATCHFILES=	roundcubemail-0.3.1-ja.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	nork@FreeBSD.org

CONFLICTS=	roundcube-[0-9]*
MASTERDIR=	${.CURDIR}/../../mail/roundcube
MD5_FILE=	${.CURDIR}/distinfo

BROKEN=		bad distinfo

.include "${MASTERDIR}/Makefile"
