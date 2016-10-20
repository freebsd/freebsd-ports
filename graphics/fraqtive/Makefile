# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fraqtive
PORTVERSION=	0.4.8
CATEGORIES=	graphics
MASTER_SITES=	SF/fraqtive/Fraqtive/Fraqtive%20${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Draws Mandelbrot and Julia fractals

USES=		qmake tar:bzip2
USE_QT4=	gui opengl xml uic_build moc_build rcc_build
USE_GL=		glu

OPTIONS_DEFINE=	SSE2
SSE2_DESC=	Enable SSE2 optimization
SSE2_QMAKE_ON=	CONFIG+=sse2
SSE2_QMAKE_OFF=	CONFIG+=no-sse2

.include <bsd.port.mk>
