# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-n-preview-5
DISTVERSION=	n-preview-5-3582
DISTVERSIONSUFFIX=	-gdfd30c4a169e
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

GH_MYTAG=	${DISTVERSIONPREFIX}${DISTVERSION:C/-[0-9]*$//}
GH_TAGNAME=	${GH_MYTAG}-907-g1a35848b34d6:extras \
		${GH_MYTAG}-43-ga63b41e:libselinux

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-fastboot
DISTINFO_FILE=	${.CURDIR}/distinfo
FILESDIR=	${.CURDIR}/files
EXTRA_PATCHES=	${.CURDIR}/files/patch-*

.include "${MASTERDIR}/Makefile"
