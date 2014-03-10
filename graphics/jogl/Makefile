# Created by: Peter Jeremy <peterjeremy@optushome.com.au>
# $FreeBSD$

PORTNAME=	jogl
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	graphics devel java
MASTER_SITES=http://download.java.net/media/jogl/builds/archive/jsr-231-1.1.1/
EXTRACT_SUFX=	-src.zip

MAINTAINER=	peterjeremy@optushome.com.au
COMMENT=	Java bindings for OpenGL

LIB_DEPENDS=	drm.2:${PORTSDIR}/graphics/libdrm
BUILD_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper     \
		${JAVALIBDIR}/antlr.jar:${PORTSDIR}/devel/antlr
RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

CONFLICTS=	jogamp-jogl-*

NO_WRKSUBDIR=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

ALL_TARGET=	all
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
.endif

# Java currently only supports i386 and amd64.  Supporting additional
# architectures will need patches to at least
# gluegen/src/java/com/sun/gluegen/StructLayout.java
# gluegen/src/java/com/sun/gluegen/runtime/CPU.java
# gluegen/make/gluegen-cpptasks.xml
# jogl/make/build.xml
ONLY_FOR_ARCHS=	i386 amd64

USES=		zip
USE_XORG=	x11 xau xdamage xdmcp xext xf86vidmodeproto xfixes xproto xt \
		xxf86vm
USE_GL=		gl
USE_ANT=	yes
USE_LDCONFIG=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

BUILD_WRKSRC=	${WRKSRC}/jogl/make

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|g' \
		${WRKSRC}/gluegen/make/build.xml
	@${REINPLACE_CMD} -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|g' \
			  -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/jogl/make/build.xml

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jogl/doc/userguide/index.html \
		${DATADIR}/UserGuide.html
	cd ${BUILD_WRKSRC}/../javadoc_public && \
		${FIND} . -print | ${CPIO} -pdm ${DATADIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/gluegen/build/obj/libgluegen-rt.so \
		${WRKSRC}/jogl/build/obj/libjogl.so \
		${WRKSRC}/jogl/build/obj/libjogl_awt.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/gluegen/build/gluegen-rt.jar \
		${WRKSRC}/jogl/build/jogl.jar ${JAVAJARDIR}

.include <bsd.port.mk>
