# ex:ts=8
# Ports collection makefile for:  mutt w/pgp hooks
# Date created:			  Thur July 25, 1996
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

CATEGORIES=	chinese

MASTERDIR=	${.CURDIR}/../../mail/mutt-devel
PORTREVISION=	5
REVISEDATE=	20020218

MAINTAINER=	ycheng@sinica.edu.tw

PATCH_SITES=	http://www.cirx.org/~clive/dist/mutt13/ \
		ftp://freebsd.sinica.edu.tw/pub/clive/mutt13/
PATCHFILES=	${PKGNAMEPREFIX}mutt-${PORTVERSION}-${REVISEDATE}.diff.gz
PATCH_DIST_ARGS=	-d ${WRKDIR} --quiet

WITH_MUTT_LOCALES_FIX=	yes
WITH_MUTT_NCURSES=	yes
.if !defined(PACKAGE_BUILDING)
WITHOUT_MUTT_SGMLFORMAT=	yes
.endif

MD5_FILE=	${.CURDIR}/distinfo
PKGMESSAGE=	${.CURDIR}/pkg-message

.include "${MASTERDIR}/Makefile"
