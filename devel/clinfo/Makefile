# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clinfo
PORTVERSION=	3.0.20.11.20
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	56a6c628555e.patch:-p1 # https://github.com/Oblomov/clinfo/pull/57

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Print information about all available OpenCL platforms/devices

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd

USE_GITHUB=	yes
GH_ACCOUNT=	Oblomov

USES=		localbase:ldflags
MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}"
ALL_TARGET=	#
PLIST_FILES=	bin/clinfo \
		man/man1/clinfo.1.gz

.include <bsd.port.mk>
