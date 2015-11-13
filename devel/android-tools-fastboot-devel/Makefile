# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-m-preview
DISTVERSION=	m-preview-5498
DISTVERSIONSUFFIX=	-g0bb1ce06ea46
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

GH_TAGNAME=	${DISTVERSIONFULL:C/-[0-9].*//}-972-g442e952:extras \
		${DISTVERSIONFULL:C/-[0-9].*//}-90-ga83098b:libselinux

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-fastboot
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
