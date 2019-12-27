# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jasper
PORTVERSION=	2.0.16
DISTVERSIONPREFIX=	version-
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of the codec specified in the JPEG-2000 standard

LICENSE=	MIT

OPTIONS_DEFINE=	OPENGL DOCS
OPTIONS_DEFAULT=	OPENGL
OPTIONS_SUB=	yes

USE_LDCONFIG=	yes
USES=		cmake jpeg localbase

USE_GITHUB=	yes

GH_ACCOUNT=	mdadams

OPENGL_CMAKE_OFF=	-DJAS_ENABLE_OPENGL=false
OPENGL_CMAKE_ON=	-DJAS_ENABLE_OPENGL=true
OPENGL_USES=		gl xorg
OPENGL_USE=		GL=glut XORG=x11,xext,xi,xmu

CMAKE_ARGS=	-DJAS_ENABLE_JPEG=true \
		-DJAS_ENABLE_AUTOMATIC_DEPENDENCIES=false \
		-DCMAKE_SKIP_RPATH=true

DOCSDIR=	${PREFIX}/share/doc/JasPer

post-install-DOCS-off:
	rm -rf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
