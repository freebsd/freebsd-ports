# New ports collection makefile for:	Open Scene Graph
# Date created:				26 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	osg
PORTVERSION=	1.2
CATEGORIES=	graphics

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	C++ OpenGL scene graph library for real-time rendering

BUILD_DEPENDS=	${LOCALBASE}/lib/libOpenThreads.so:${PORTSDIR}/devel/openthreads \
		${LOCALBASE}/lib/libProducer.so:${PORTSDIR}/graphics/openproducer
RUN_DEPENDS=	${LOCALBASE}/lib/libOpenThreads.so:${PORTSDIR}/devel/openthreads \
		${LOCALBASE}/lib/libProducer.so:${PORTSDIR}/graphics/openproducer
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2

USE_GL=		yes
WRKSRC=		${WRKDIR}/${DISTNAME}/OpenSceneGraph

.include "${.CURDIR}/bsd.osg.mk"
.include <bsd.port.mk>
