# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-n-preview-5
DISTVERSION=	n-preview-5-126
DISTVERSIONSUFFIX=	-g2f21b7cecda2
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

GH_MYTAG=	${DISTVERSIONPREFIX}${DISTVERSION:C/-[0-9]*$//}
GH_TAGNAME=	${GH_MYTAG}-64-g8cd939bd7af7:extras \
		${GH_MYTAG}-1-g1fdb726:libselinux

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-fastboot
DISTINFO_FILE=	${.CURDIR}/distinfo
FILESDIR=	${.CURDIR}/files
EXTRA_PATCHES=	${.CURDIR}/files/patch-*

.include "${MASTERDIR}/Makefile"
