# ex: ts=8
# New ports collection Makefile for:	meshlab
# Date created:				26 October 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	meshlab
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/MeshLab%20v${PORTVERSION}/
DISTNAME=	MeshLabSrc_AllInc_v123a
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A tool for processing and editing 3D triangular meshes

USE_GL=		glew glu
USE_QT_VER=	4
QT_COMPONENTS=	qmake corelib gui xml opengl network moc uic rcc

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/meshlab/src

post-patch:
	${FIND} ${WRKSRC} -name "*.pro" | ${XARGS} ${REINPLACE_CMD} -e 's|^linux-g++|freebsd-g++|'
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
	   ${WRKSRC}/common/pluginmanager.cpp

do-configure:
	cd ${WRKSRC}/external && ${QMAKE} -recursive external.pro
	cd ${WRKSRC} && ${QMAKE} -recursive meshlabv12.pro

do-build:
	cd ${WRKSRC}/external && ${MAKE}
	cd ${WRKSRC} && ${MAKE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/distrib/libcommon.so.1.0.0 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libcommon.so.1.0.0 ${PREFIX}/lib/libcommon.so.1.0
	${LN} -sf ${PREFIX}/lib/libcommon.so.1.0 ${PREFIX}/lib/libcommon.so.1
	${LN} -sf ${PREFIX}/lib/libcommon.so.1 ${PREFIX}/lib/libcommon.so
	${MKDIR} ${PREFIX}/lib/meshlab/plugins
	cd ${WRKSRC}/distrib/plugins && ${COPYTREE_SHARE} \*.so ${PREFIX}/lib/meshlab/plugins
	${MKDIR} ${PREFIX}/lib/meshlab/shaders
	cd ${WRKSRC}/distrib/shaders && ${COPYTREE_SHARE} \* ${PREFIX}/lib/meshlab/shaders
	${INSTALL_PROGRAM} ${WRKSRC}/distrib/meshlab ${PREFIX}/lib/meshlab
	${LN} -sf ${PREFIX}/lib/meshlab/meshlab ${PREFIX}/bin

.include <bsd.port.mk>
