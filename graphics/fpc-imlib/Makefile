# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-imlib

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to imlib library

USE_FPC=	gtk1 x11 opengl

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	IMLIB2
IMLIB2_DESC=	Install imlib graphic library
OPTIONS_DEFAULT=	IMLIB2

IMLIB2_USE=	EFL=imlib2

.include "${MASTERDIR}/Makefile"
