# $FreeBSD$

DISTVERSION=	m-preview-190
DISTVERSIONSUFFIX=	-g683790a
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

GH_TAGNAME=	m-preview-100-gdece0f9:extras \
		m-preview-6-g6d0b91b:libselinux

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-fastboot
DISTINFO_FILE=	${.CURDIR}/distinfo
MAKEFILE=	${.CURDIR}/files/Makefile
EXTRA_PATCHES+=	${.CURDIR}/files/patch-*

USES=		compiler:c++11-lib
CFLAGS+=	-DFASTBOOT_REVISION='\"${DISTVERSIONFULL}\"'

.include "${MASTERDIR}/Makefile"
