# New ports collection makefile for:	openproducer
# Date created:		22 July 2003
# Whom:			Ying-Chieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	openproducer
PORTVERSION=	1.1
CATEGORIES=	graphics

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A cross-platform C++/OpenGL library focused on camera control

BUILD_DEPENDS=	${LOCALBASE}/lib/libOpenThreads.so:${PORTSDIR}/devel/openthreads
RUN_DEPENDS=	${LOCALBASE}/lib/libOpenThreads.so:${PORTSDIR}/devel/openthreads

USE_GL=		yes
WRKSRC=		${WRKDIR}/${DISTNAME}/Producer

.include "${.CURDIR}/../../graphics/osg/bsd.osg.mk"
.include <bsd.port.mk>
