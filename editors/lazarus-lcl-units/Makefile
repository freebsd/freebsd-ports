# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-lcl-units

COMMENT=	Lazarus components library units

USE_FPC=	fcl-base fcl-db fcl-image fcl-process fcl-registry fcl-xml iconvenc fcl-res

LCL_INTERFACE=	#

MASTERDIR=	${.CURDIR}/../../editors/lazarus

OPT=		"-Fu../../lcl/ -Fu../lcl -Fu../../lcl/forms -Fu../../lcl/nonwin32 -Fu../../lcl/widgetset -Fi../../lcl/include"

.include "${MASTERDIR}/Makefile"
