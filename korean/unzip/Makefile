# Ports collection makefile for:  ko-unzip
# Date created:		21 May 2003
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

CATEGORIES=	korean archivers

MAINTAINER=	ab@astralblue.net
COMMENT=	ZIP archive extractor with localized patches

CONFLICTS=	unzip-[0-9]* ru-unzip-[0-9]* zh-unzip-[0-9]*

EXTRA_PATCHES=	${.CURDIR}/files/patch-*
MASTERDIR=	${.CURDIR}/../../archivers/unzip

.include "${MASTERDIR}/Makefile"
