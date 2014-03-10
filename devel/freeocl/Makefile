# Created by: Oliver Hartmann <ohartman@zedat.fu-berlin.de>
# $FreeBSD$

PORTNAME=	freeocl
PORTVERSION=	0.3.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	FreeOCL-${PORTVERSION}-src

MAINTAINER=	ohartman@zedat.fu-berlin.de
COMMENT=	Free Open Computing Language (OpenCL) implementation for CPU

BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:${PORTSDIR}/devel/libatomic_ops \
		${LOCALBASE}/include/CL/opencl.h:${PORTSDIR}/devel/opencl

LICENSE=	LGPL3

WRKSRC=		${WRKDIR}/FreeOCL-${PORTVERSION}-Source

USE_GCC=	yes
USES=		cmake
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's:%%PREFIX%%:${PREFIX}:g' ${WRKSRC}/src/icd/icd_loader.cpp \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
