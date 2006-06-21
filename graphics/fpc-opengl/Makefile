# New ports collection makefile for:	fpc-opengl
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-opengl

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free Pascal interface to the OpenGL library

RUN_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

USE_GL=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc

.include "${MASTERDIR}/Makefile"
