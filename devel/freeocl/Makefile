# Created by: Oliver Hartmann <ohartman@zedat.fu-berlin.de>
# $FreeBSD$

PORTNAME=	freeocl
PORTVERSION=	0.3.6
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	FreeOCL-${PORTVERSION}-src

MAINTAINER=	ohartman@zedat.fu-berlin.de
COMMENT=	Free Open Computing Language (OpenCL) implementation for CPU

LICENSE=	LGPL3

BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:${PORTSDIR}/devel/libatomic_ops \
		${LOCALBASE}/include/CL/opencl.h:${PORTSDIR}/devel/opencl

CONFLICTS=	ocl-icd[0-9]* opencl-icd[0-9]* pocl[0-9]*

WRKSRC=		${WRKDIR}/FreeOCL-${PORTVERSION}-Source

USE_GCC=	any
USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

CXXFLAGS+=	-pthread -std=gnu++0x
CMAKE_ENV+=	FREEOCL_CXX_COMPILER="${CXX}"

CFLAGS_i386=	-msse

post-patch:
		${REINPLACE_CMD} -e 's:%%PREFIX%%:${PREFIX}:g' ${WRKSRC}/src/icd/icd_loader.cpp \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
