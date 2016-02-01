# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-m-preview
DISTVERSION=	m-preview-6225
DISTVERSIONSUFFIX=	-gaef26bb1a4ad
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

GH_TAGNAME=	${DISTVERSIONFULL:C/-[0-9].*//}-1153-gb764f45:extras \
		${DISTVERSIONFULL:C/-[0-9].*//}-96-g589c5ac:libselinux

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-fastboot
FILESDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
