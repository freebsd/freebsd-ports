# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-o-preview-4
DISTVERSION=	o-preview-4-4534
DISTVERSIONSUFFIX=	-g612b47630f6f
PKGNAMESUFFIX=	-devel

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-adb
DISTINFO_FILE=	${.CURDIR}/distinfo
EXTRA_PATCHES=	${.CURDIR}/files/patch-*

GH_MYTAG=	${DISTVERSIONPREFIX}${DISTVERSION:C/-[0-9]*$//}

TEST_PYTHON_GH_TAGNAME=	${GH_MYTAG}-62-g417a8e237642:development

.include "${MASTERDIR}/Makefile"
