# Created by: Oliver Hartmann <ohartman@zedat.fu-berlin.de>
# $FreeBSD$

PORTNAME=	opencl
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	ohartman@zedat.fu-berlin.de
COMMENT=	Open Computing Language (OpenCL) specifications V2.2 (header files)

LICENSE=	unknown
LICENSE_NAME=	BSD-esque license agreement
LICENSE_TEXT=	License is included in each of the header files of this port
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS=	opencl-1.[0-2]

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	OpenCL-Headers OpenCL-CLHPP:clhpp
GH_TAGNAME=	${HEADER_TAG} ${CLHPP_TAG}:clhpp

# the header releases don't have tags yet, so use git commit for now
HEADER_TAG=	f039db6
CLHPP_TAG=	8b6a312

USES=		python:build
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME}/opencl${PORTVERSION:S/.//}/CL

do-build:
	@cd ${WRKSRC_clhpp} && ${PYTHON_CMD} gen_cl_hpp.py

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/CL
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/CL
	${INSTALL_DATA} ${WRKSRC_clhpp}/cl.hpp \
		${STAGEDIR}${PREFIX}/include/CL/cl.hpp
	${INSTALL_DATA} ${WRKSRC_clhpp}/input_cl2.hpp \
		${STAGEDIR}${PREFIX}/include/CL/cl2.hpp

.include <bsd.port.mk>
