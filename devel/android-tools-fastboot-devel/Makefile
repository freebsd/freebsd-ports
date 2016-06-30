# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-n-preview-4
DISTVERSION=	n-preview-4-74
DISTVERSIONSUFFIX=	-g80beb506cf84
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

GH_MYTAG=	${DISTVERSIONPREFIX}${DISTVERSION:C/-[0-9]*$//}
GH_TAGNAME=	${GH_MYTAG}-38-gd937202:extras \
		${GH_MYTAG}:libselinux

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-fastboot
DISTINFO_FILE=	${.CURDIR}/distinfo
FILESDIR=	${.CURDIR}/files
EXTRA_PATCHES=	${.CURDIR}/files/patch-*

.include "${MASTERDIR}/Makefile"
