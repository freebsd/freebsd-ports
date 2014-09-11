# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-fpgtk

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Component Library for create programs with gtk

USE_FPC=	fcl-base gtk1 x11 opengl

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	GTK1
GTK1_DESC=	Gimp Toolkit for X11 GUI (version 1.x)
OPTIONS_DEFAULT=	GTK1

GTK1_USE=	GNOME=gtk12

.include "${MASTERDIR}/Makefile"
