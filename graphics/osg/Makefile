# New ports collection makefile for:	Open Scene Graph
# Date created:				26 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	osg
PORTVERSION=	0.8.44
CATEGORIES=	graphics
MASTER_SITES=	http://www.openscenegraph.org/download/snapshots/

MAINTAINER=	aa8vb@nc.rr.com

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2

USE_X_PREFIX=	yes
USE_MESA=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	OSGHOME=${WRKSRC}
ALL_TARGET=	freebsd

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/src/osgPlugins/flt/Input.cpp \
		${WRKSRC}/src/osgPlugins/flt/Record.cpp \
		${WRKSRC}/src/osgPlugins/obj/glm.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/osgconv ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/sgv ${PREFIX}/bin
	${FIND} ${WRKSRC}/include -name '*.orig' --delete
	${CP} -r ${WRKSRC}/include/ ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/lib/libosg.so ${PREFIX}/lib/libosg.so.1
	${INSTALL_DATA} ${WRKSRC}/lib/libosgDB.so ${PREFIX}/lib/libosgDB.so.1
	${INSTALL_DATA} ${WRKSRC}/lib/libosgGLUT.so ${PREFIX}/lib/libosgGLUT.so.1
	${INSTALL_DATA} ${WRKSRC}/lib/libosgText.so ${PREFIX}/lib/libosgText.so.1
	${INSTALL_DATA} ${WRKSRC}/lib/libosgUtil.so ${PREFIX}/lib/libosgUtil.so.1
	${LN} -sf ${PREFIX}/lib/libosg.so.1 ${PREFIX}/lib/libosg.so
	${LN} -sf ${PREFIX}/lib/libosgDB.so.1 ${PREFIX}/lib/libosgDB.so
	${LN} -sf ${PREFIX}/lib/libosgGLUT.so.1 ${PREFIX}/lib/libosgGLUT.so
	${LN} -sf ${PREFIX}/lib/libosgText.so.1 ${PREFIX}/lib/libosgText.so
	${LN} -sf ${PREFIX}/lib/libosgUtil.so.1 ${PREFIX}/lib/libosgUtil.so
	@${MKDIR} ${PREFIX}/lib/osgPlugins
	${CP} -p ${WRKSRC}/lib/osgPlugins/* ${PREFIX}/lib/osgPlugins
	@${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/doc/ ${DOCSDIR}

.include <bsd.port.mk>
