# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
PKGNAMESUFFIX=	-lcl-qt

COMMENT=	Lazarus components library - QT backend

BUILD_DEPENDS=	${LCL_UNITS_DIR}/alllclunits.ppu:${PORTSDIR}/editors/lazarus-lcl-units

USE_FPC=	x11
USE_FPC_RUN=	yes

LCL_INTERFACE=	qt

MASTERDIR=	${.CURDIR}/../../editors/lazarus

.include "${MASTERDIR}/Makefile"
