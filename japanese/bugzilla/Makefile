# New ports collection makefile for:	ja-bugzilla
# Date created:		2004-01-19
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	bugzilla
PORTVERSION=	2.16.6
CATEGORIES=	japanese devel

PATCH_SITES=	http://hp.vector.co.jp/authors/VA013241/webapp/bugzilla/
PATCHFILES=	${PORTNAME}-${PORTVERSION}-to-${PORTNAME}-${PORTVERSION}-ja-${PATCHVERSION}.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tota@rtfm.jp
COMMENT=	Bug-tracking system with Japanese patch

CONFLICTS=	bugzilla-2.*
PATCHVERSION=	20040714

MASTERDIR=	${.CURDIR}/../../devel/bugzilla
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
