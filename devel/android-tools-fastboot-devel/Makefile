# $FreeBSD$

DISTVERSION=	m-preview-122
DISTVERSIONSUFFIX=	-g53d504f
PORTREVISION=	0
PKGNAMESUFFIX=	-devel

GH_TAGNAME=	m-preview-36-gb9408ad:extras \
		m-preview-1-g06d4551:libselinux

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../android-tools-fastboot
DISTINFO_FILE=	${.CURDIR}/distinfo
MAKEFILE=	${.CURDIR}/files/Makefile
EXTRA_PATCHES+=	${.CURDIR}/files/patch-*

USES=		compiler:c++11-lib
CFLAGS+=	-DFASTBOOT_REVISION='\"${DISTVERSIONFULL}\"'

.include "${MASTERDIR}/Makefile"
