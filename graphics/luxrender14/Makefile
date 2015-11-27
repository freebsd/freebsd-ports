# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

DISTVERSION=	1.4
DISTFILES=	v${DISTVERSION:C/[.-]//g}${EXTRACT_SUFX} \
		${PORTNAME}_v${DISTVERSION:S/-//}${EXTRACT_SUFX}:lr

LUX_REV=	dfd211d6faa0
LUXRAYS_REV=	7c7127ee1fa4

MASTERDIR=	${.CURDIR}/../luxrender
PKGNAMESUFFIX=	14

DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files

.include "${MASTERDIR}/Makefile"
