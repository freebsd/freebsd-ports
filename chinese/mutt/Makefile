# ex:ts=8
# Ports collection makefile for:  mutt w/pgp hooks
# Date created:			  Thur July 25, 1996
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

CATEGORIES=	chinese

MASTERDIR=	${.CURDIR}/../../mail/mutt-devel
REVISEDATE=	20020617

MAINTAINER=	ycheng@sinica.edu.tw

PATCH_SITES=	http://bsdchat.com/~clive/dist/mutt15/ \
		ftp://freebsd.sinica.edu.tw/pub/clive/mutt15/
PATCHFILES=	${PKGNAMEPREFIX}mutt-${PORTVERSION}-${REVISEDATE}.diff.gz
PATCH_DIST_ARGS=	-d ${WRKDIR} --quiet

WITH_MUTT_LOCALES_FIX=	yes
WITH_MUTT_NCURSES=	yes
WITH_MUTT_PGP_OUTLOOK_PATCH=	yes
.if !defined(PACKAGE_BUILDING)
WITHOUT_MUTT_SGMLFORMAT=	yes
.endif

MD5_FILE=	${.CURDIR}/distinfo
PKGMESSAGE=	${.CURDIR}/pkg-message

.include "${MASTERDIR}/Makefile"
