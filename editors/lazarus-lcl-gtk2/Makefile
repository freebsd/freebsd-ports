# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
PKGNAMESUFFIX=	-lcl-gtk2

COMMENT=	Lazarus components library - GTK2 backend

BUILD_DEPENDS=	${LCL_UNITS_DIR}/alllclunits.ppu:${PORTSDIR}/editors/lazarus-lcl-units

USE_FPC=	x11 gtk2

LCL_INTERFACE=	gtk2

MASTERDIR=	${.CURDIR}/../../editors/lazarus

NO_STAGE=	yes

OPT=		#
.include "${MASTERDIR}/Makefile"
