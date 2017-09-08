# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-o-preview-2
DISTVERSION=	o-preview-2-332
DISTVERSIONSUFFIX=	-gd1e9e7bc06f0
PORTREVISION=	1
PKGNAMESUFFIX=	-devel

GH_MYTAG=	${DISTVERSIONPREFIX}${DISTVERSION:C/-[0-9]*$//}
GH_TAGNAME=	${GH_MYTAG}-50-gebf42931:extras \
		${GH_MYTAG}-43-ga63b41e:libselinux

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-fastboot
DISTINFO_FILE=	${.CURDIR}/distinfo
EXTRA_PATCHES=	${.CURDIR}/files/patch-*

.include "${MASTERDIR}/Makefile"
