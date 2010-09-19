# New ports collection makefile for:	jogamp-jogl
# Date created:		2010-09-18
# Whom:			Tassilo Philipp <tphilipp@potion-studios.com>
#
# $FreeBSD$
#

PORTNAME=	jogamp-jogl
PORTVERSION=	2.0.20100914
CATEGORIES=	graphics devel java
MASTER_SITES=	http://www.potion-studios.com/ \
		LOCAL/makc
DISTFILES=	sgothel-gluegen-VALID_BUILDS_01-144-ga61c650.tar.gz \
		sgothel-jogl-OpenGL_3_3_Integration-8-gdc9191f.tar.gz

MAINTAINER=	tphilipp@potion-studios.com
COMMENT=	Java bindings for OpenGL

LIB_DEPENDS=	drm.2:${PORTSDIR}/graphics/libdrm
BUILD_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper     \
		${JAVALIBDIR}/antlr.jar:${PORTSDIR}/devel/antlr
RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

CONFLICTS=	jogl-1.*

MAKE_ENV+=	_JAVA_OPTIONS="-Xmx256m"
NO_WRKSUBDIR=	yes
WRKSRC=		${WRKDIR}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

ALL_TARGET=	all

# This JOGL port features supported for i386 and amd64, only.
ONLY_FOR_ARCHS=	i386 amd64

USE_XORG=	x11 xau xdamage xdmcp xext xf86vidmodeproto xfixes xproto xt \
		xxf86vm
USE_GL=		gl
USE_ANT=	yes
USE_LDCONFIG=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

BUILD_WRKSRC=	${WRKDIR}/jogl/make

post-extract:
	${MV} ${WRKDIR}/sgothel-gluegen-a61c650 ${WRKDIR}/gluegen
	${MV} ${WRKDIR}/sgothel-jogl-dc9191f ${WRKDIR}/jogl

post-patch:
	@${REINPLACE_CMD} -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|g' \
		${WRKDIR}/gluegen/make/build.xml \
		${WRKDIR}/gluegen/make/gluegen.properties
	@${REINPLACE_CMD} -e 's|%%WRKSRC%%|${WRKDIR}|g' \
		${WRKDIR}/gluegen/make/gluegen-properties.xml

do-install:
	cd ${WRKDIR}/jogl/build/lib && ${INSTALL_DATA} \
		libgluegen-rt.so \
		libjogl_desktop.so \
		libjogl_es1.so \
		libjogl_es2.so \
		libjogl_gl2es12.so \
		libnativewindow_awt.so \
		libnativewindow_x11.so \
		libnewt.so \
		${PREFIX}/lib
	cd ${WRKDIR}/jogl/build/jar && ${INSTALL_DATA} \
		gluegen-rt-cdc.jar \
		gluegen-rt.jar \
		jogl.all-noawt.jar \
		jogl.all.cdc.jar \
		jogl.all.jar \
		jogl.awt.jar \
		jogl.core.cdc.jar \
		jogl.core.jar \
		jogl.egl.cdc.jar \
		jogl.egl.jar \
		jogl.gl2es12.cdc.jar \
		jogl.gl2es12.jar \
		jogl.gldesktop.dbg.jar \
		jogl.gldesktop.jar \
		jogl.gles1.cdc.jar \
		jogl.gles1.dbg.cdc.jar \
		jogl.gles1.dbg.jar \
		jogl.gles1.jar \
		jogl.gles2.cdc.jar \
		jogl.gles2.dbg.cdc.jar \
		jogl.gles2.dbg.jar \
		jogl.gles2.jar \
		jogl.glu.gldesktop.jar \
		jogl.glu.mipmap.cdc.jar \
		jogl.glu.mipmap.jar \
		jogl.glu.tess.cdc.jar \
		jogl.glu.tess.jar \
		jogl.os.x11.cdc.jar \
		jogl.os.x11.jar \
		jogl.sdk.jar \
		jogl.test.jar \
		jogl.util.awt.jar \
		jogl.util.cdc.jar \
		jogl.util.fixedfuncemu.cdc.jar \
		jogl.util.fixedfuncemu.jar \
		jogl.util.gldesktop.jar \
		jogl.util.jar \
		nativewindow.all-noawt.jar \
		nativewindow.all.cdc.jar \
		nativewindow.all.jar \
		nativewindow.awt.jar \
		nativewindow.core.cdc.jar \
		nativewindow.core.jar \
		nativewindow.os.x11.cdc.jar \
		nativewindow.os.x11.jar \
		newt.all-noawt.jar \
		newt.all.cdc.jar \
		newt.all.jar \
		newt.awt.jar \
		newt.broadcomegl.cdc.jar \
		newt.broadcomegl.jar \
		newt.core.cdc.jar \
		newt.core.jar \
		newt.intelgdl.cdc.jar \
		newt.intelgdl.jar \
		newt.ogl.cdc.jar \
		newt.ogl.jar \
		newt.os.x11.cdc.jar \
		newt.os.x11.jar \
		${JAVAJARDIR}

.include <bsd.port.mk>
