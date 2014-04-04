# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
PKGNAMESUFFIX=	-lcl-nogui

COMMENT=	Lazarus components library - No gui backend

BUILD_DEPENDS=	${LCL_UNITS_DIR}/alllclunits.ppu:${PORTSDIR}/editors/lazarus-lcl-units

LCL_INTERFACE=	nogui

MASTERDIR=	${.CURDIR}/../../editors/lazarus

NO_STAGE=	yes

OPT=		#
.include "${MASTERDIR}/Makefile"
