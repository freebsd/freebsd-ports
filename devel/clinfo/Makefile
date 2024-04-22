PORTNAME=	clinfo
PORTVERSION=	3.0.23.01.25
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Print information about all available OpenCL platforms/devices
WWW=		https://github.com/Oblomov/clinfo

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd

USE_GITHUB=	yes
GH_ACCOUNT=	Oblomov

USES=		gmake localbase:ldflags

MAKE_ARGS+=	MANDIR=${PREFIX}/share/man

ALL_TARGET=	#
PLIST_FILES=	bin/clinfo \
		share/man/man1/clinfo.1.gz

.include <bsd.port.mk>
