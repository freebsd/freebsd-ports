# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-lcl-qt5

COMMENT=	Lazarus components library - QT5 backend

BUILD_DEPENDS=	${LCL_UNITS_DIR}/alllclunits.ppu:editors/lazarus-lcl-units

USE_FPC=	chm fcl-base fcl-db fcl-image fcl-json fcl-registry fcl-res \
		fcl-xml pasjpeg regexpr x11

LCL_INTERFACE=	qt5

MASTERDIR=	${.CURDIR}/../../editors/lazarus

.include "${MASTERDIR}/Makefile"
