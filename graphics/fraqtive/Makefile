PORTNAME=	fraqtive
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.8.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Draws Mandelbrot and Julia fractals
WWW=		https://fraqtive.mimec.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang dos2unix gl qmake qt:5
USE_QT=		core gui opengl widgets xml buildtools:build
USE_GL=		gl glu
USE_GITHUB=	yes
GH_ACCOUNT=	mimecorg

OPTIONS_DEFINE=	SSE2
OPTIONS_DEFAULT_amd64=	SSE2
OPTIONS_DEFAULT_i386=	SSE2
SSE2_DESC=	Enable SSE2 optimization
SSE2_QMAKE_ON=	CONFIG+=sse2
SSE2_QMAKE_OFF=	CONFIG+=no-sse2

DOS2UNIX_FILES=	src/shadewidget.cpp

.include <bsd.port.mk>
