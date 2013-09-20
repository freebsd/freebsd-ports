# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-lcl-gtk

COMMENT=	Lazarus components library - GTK backend

BUILD_DEPENDS=	${LCL_UNITS_DIR}/alllclunits.ppu:${PORTSDIR}/editors/lazarus-lcl-units

USE_FPC=	x11 gtk1

LCL_INTERFACE=	gtk

MASTERDIR=	${.CURDIR}/../../editors/lazarus

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
