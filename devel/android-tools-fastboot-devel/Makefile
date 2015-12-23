# $FreeBSD$

# Hint: git describe --abbrev=12 --match android-m-preview
DISTVERSION=	m-preview-5956
DISTVERSIONSUFFIX=	-g461a29540c01
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

GH_TAGNAME=	${DISTVERSIONFULL:C/-[0-9].*//}-1071-g4f5860d:extras \
		${DISTVERSIONFULL:C/-[0-9].*//}-94-gbe5f860:libselinux

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-fastboot
FILESDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
