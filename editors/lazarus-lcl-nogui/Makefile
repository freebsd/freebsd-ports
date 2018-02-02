# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-lcl-nogui

COMMENT=	Lazarus components library - No gui backend

BUILD_DEPENDS=	${LCL_UNITS_DIR}/alllclunits.ppu:editors/lazarus-lcl-units

USE_FPC=	chm fcl-base fcl-db fcl-image fcl-json fcl-registry fcl-xml \
		pasjpeg regexpr rtl-objpas

LCL_INTERFACE=	nogui

MASTERDIR=	${.CURDIR}/../../editors/lazarus

OPT=		#
.include "${MASTERDIR}/Makefile"
