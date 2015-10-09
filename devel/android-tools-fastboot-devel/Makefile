# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-m-preview
DISTVERSION=	m-preview-1212
DISTVERSIONSUFFIX=	-g94c617ccbba4
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

GH_TAGNAME=	${DISTVERSIONFULL:C/-[0-9].*//}-195-g7434d1f:extras \
		${DISTVERSIONFULL:C/-[0-9].*//}-19-g249094f:libselinux

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-fastboot
DISTINFO_FILE=	${.CURDIR}/distinfo
FILESDIR=	${.CURDIR}/files
EXTRA_PATCHES+=	${.CURDIR}/files/patch-*

USES=		compiler:c++11-lib
CPPFLAGS+=	-DFASTBOOT_REVISION='\"${DISTVERSIONSUFFIX:S/-g//}-android\"'

.include "${MASTERDIR}/Makefile"
