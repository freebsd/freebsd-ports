# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-o-preview-2
DISTVERSION=	o-preview-2-332
DISTVERSIONSUFFIX=	-gd1e9e7bc06f0
PORTREVISION=	1
PKGNAMESUFFIX=	-devel

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-adb
DISTINFO_FILE=	${.CURDIR}/distinfo
EXTRA_PATCHES=	${.CURDIR}/files/patch-*

GH_MYTAG=	${DISTVERSIONPREFIX}${DISTVERSION:C/-[0-9]*$//}

TEST_PYTHON_GH_TAGNAME=	${GH_MYTAG}-83-gc5efdcc74:development

.include "${MASTERDIR}/Makefile"
