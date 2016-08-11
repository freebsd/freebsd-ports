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

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops \
		${LOCALBASE}/include/CL/opencl.h:devel/opencl

CONFLICTS=	ocl-icd[0-9]* opencl-icd[0-9]* pocl[0-9]*

WRKSRC=		${WRKDIR}/FreeOCL-${PORTVERSION}-Source

USE_GCC=	any
USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

CXXFLAGS+=	-pthread -std=gnu++0x

CFLAGS_i386=	-msse

post-patch:
		${REINPLACE_CMD} -e 's:%%PREFIX%%:${PREFIX}:g' ${WRKSRC}/src/icd/icd_loader.cpp \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
