# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-lcl-gtk2

COMMENT=	Lazarus components library - GTK2 backend

BUILD_DEPENDS=	${LCL_UNITS_DIR}/alllclunits.ppu:editors/lazarus-lcl-units

USE_FPC=	cairo chm fcl-base fcl-db fcl-image fcl-json fcl-res \
		fcl-registry fcl-xml gtk2 pasjpeg regexpr x11

LCL_INTERFACE=	gtk2

MASTERDIR=	${.CURDIR}/../../editors/lazarus

OPT=		#
.include "${MASTERDIR}/Makefile"
