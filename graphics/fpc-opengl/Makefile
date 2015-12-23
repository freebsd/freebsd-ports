# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-opengl

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal interface to the OpenGL library

USE_FPC=	x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	EXAMPLES OPENGL
OPENGL_DESC=	Install opengl libraries
OPTIONS_DEFAULT=	OPENGL

OPENGL_USE=	GL=glut
HAVE_EXAMPLES=	yes

.include "${MASTERDIR}/Makefile"
