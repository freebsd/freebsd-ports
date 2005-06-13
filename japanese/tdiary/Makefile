# New ports collection makefile for:    tdiary
# Date created:                 21 May 2003
# Whom:                         Fumihiko Kimura <jfkimura@yahoo.co.jp>
#
# $FreeBSD$
#

CATEGORIES=	japanese www ruby

MAINTAINER=	jfkimura@yahoo.co.jp

TDIARY_LANG=	tdiary.conf-ja
MASTERDIR?=	${.CURDIR}/../../www/tdiary

.if	defined(WITH_TDIARY_DEVEL)
CONFLICTS=	tdiary-devel-[0-9]*
PKGNAMESUFFIX=	-devel
MASTERDIR=	${.CURDIR}/../../www/tdiary-devel
MD5_FILE=	${.CURDIR}/../../www/tdiary-devel/distinfo
.else
CONFLICTS=	tdiary-[0-9]*
MD5_FILE=	${.CURDIR}/../../www/tdiary/distinfo
.endif

.include "${MASTERDIR}/Makefile"
