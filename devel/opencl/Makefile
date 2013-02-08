# Created by: Oliver Hartmann <ohartman@zedat.fu-berlin.de>
# $FreeBSD$

PORTNAME=	opencl
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.khronos.org/registry/cl/api/${PORTVERSION}/
DISTFILES=	opencl.h cl_platform.h cl.h cl_ext.h cl_dx9_media_sharing.h \
		cl_d3d10.h cl_d3d11.h  cl_gl.h cl_gl_ext.h cl.hpp
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	ohartman@zedat.fu-berlin.de
COMMENT=	Open Computing Language (OpenCL) specifications

CONFLICTS=	opencl-1.[0-1]

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_DIRS=	include/CL
.for f in ${DISTFILES}
PLIST_FILES+=include/CL/$f
.endfor

do-install:
		${MKDIR} ${PREFIX}/include/CL
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.h  ${PREFIX}/include/CL
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.hpp  ${PREFIX}/include/CL

.include <bsd.port.mk>
