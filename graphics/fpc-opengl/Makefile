# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-opengl

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the OpenGL library

USE_FPC=	x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	OPENGL
OPENGL_DESC=	Install opengl libraries
OPTIONS_DEFAULT=	OPENGL

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
