# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cltune
PORTVERSION=	2.7.0
CATEGORIES=	devel

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Library to tune OpenCL kernels

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to build: GCC version must be at least 4.7

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

USES=		cmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	CNugteren
GH_PROJECT=	CLTune

PLIST_FILES=	include/cltune.h \
		lib/libcltune.so \
		libdata/pkgconfig/cltune.pc

.include <bsd.port.mk>
