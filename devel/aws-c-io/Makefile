PORTNAME=	aws-c-io
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.21
PORTREVISION=	1
CATEGORIES=	devel
PATCH_SITES=	https://github.com/awslabs/aws-c-io/commit/
PATCHFILES=	4dc663c0c3f7cf1e3aebb1d8e28dd48f012e3db8.patch:-p1

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Event driven framework for implementing application protocols
WWW=		https://github.com/awslabs/aws-c-io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaws-c-cal.so:security/aws-c-cal \
		libaws-c-common.so:devel/aws-c-common \
		libs2n.so:security/s2n-tls

USES=		cmake:testing compiler:c11 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	awslabs
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_INSTALL_LIBDIR=${LOCALBASE}/lib
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
