# Created by: Oliver Hartmann <ohartman@zedat.fu-berlin.de>
# $FreeBSD$

PORTNAME=	opencl
PORTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://www.khronos.org/registry/cl/api/${PORTVERSION}/
DISTFILES=	opencl.h cl_platform.h cl.h cl_ext.h cl_dx9_media_sharing.h \
		cl_d3d10.h cl_d3d11.h  cl_gl.h cl_gl_ext.h cl.hpp
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	ohartman@zedat.fu-berlin.de
COMMENT=	Open Computing Language (OpenCL) specifications V1.2 (header files)

CONFLICTS=	opencl-1.[0-1]

NO_BUILD=	yes

PLIST_DIRS+=	include/CL
.for f in ${DISTFILES}
PLIST_FILES+=include/CL/$f
.endfor

NO_STAGE=	yes
pre-patch:
		@${MKDIR} ${WRKSRC}
.for f in ${DISTFILES}
		@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$f ${WRKSRC}/
.endfor

do-install:
		@${MKDIR} ${PREFIX}/include/CL
.for f in ${DISTFILES}
		@${INSTALL_DATA} ${WRKSRC}/$f  ${PREFIX}/include/CL
.endfor

.include <bsd.port.mk>
