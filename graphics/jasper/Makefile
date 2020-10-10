# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jasper
PORTVERSION=	2.0.22
DISTVERSIONPREFIX=	version-
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of the codec specified in the JPEG-2000 standard

LICENSE=	JASPER
LICENSE_NAME=	JasPer License Version 2.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake jpeg localbase

CMAKE_OFF=	JAS_ENABLE_AUTOMATIC_DEPENDENCIES
CMAKE_ON=	JAS_ENABLE_LIBJPEG
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/JasPer

USE_GITHUB=	yes
GH_ACCOUNT=	jasper-software

OPTIONS_DEFINE=	OPENGL DOCS
OPTIONS_DEFAULT=OPENGL
OPTIONS_SUB=	yes

DOCS_CMAKE_BOOL=	JAS_ENABLE_DOC
OPENGL_CMAKE_BOOL=	JAS_ENABLE_OPENGL
OPENGL_USE=		GL=gl,glu,glut XORG=x11,xext,xi,xmu
OPENGL_USES=		gl xorg

.include <bsd.port.mk>
