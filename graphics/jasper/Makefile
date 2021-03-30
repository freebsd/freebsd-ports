# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jasper
PORTVERSION=	2.0.25
DISTVERSIONPREFIX=	version-
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of the codec specified in the JPEG-2000 standard

LICENSE=	JASPER
LICENSE_NAME=	JasPer License Version 2.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake cpe jpeg localbase

CMAKE_OFF=	JAS_ENABLE_AUTOMATIC_DEPENDENCIES JAS_ENABLE_DOC
CMAKE_ON=	JAS_ENABLE_LIBJPEG
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/JasPer

USE_GITHUB=	yes
GH_ACCOUNT=	jasper-software

CPE_VENDOR=	jasper_project

OPTIONS_DEFINE=	OPENGL DOCS
OPTIONS_DEFAULT=OPENGL
OPTIONS_SUB=	yes

OPENGL_CMAKE_BOOL=	JAS_ENABLE_OPENGL
OPENGL_USE=		GL=gl,glu,glut XORG=x11,xext,xi,xmu
OPENGL_USES=		gl xorg

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/jasper.pdf ${WRKSRC}/doc/jpeg2000.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
