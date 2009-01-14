# New ports collection makefile for:	fpc-fpgtk
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-fpgtk

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Component Library for create programs with gtk

USE_FPC=	fcl-base gtk1 x11 opengl

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	GTK1	"Gimp Toolkit for X11 GUI (version 1.x)"	on

.include "${MASTERDIR}/Makefile"
