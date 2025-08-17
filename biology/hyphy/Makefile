PORTNAME=	hyphy
DISTVERSION=	2.5.77
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Hypothesis testing using Phylogenies
WWW=		https://www.hyphy.org/ \
		https://github.com/veg/hyphy/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc powerpc64 powerpc64le

LIB_DEPENDS=	libcurl.so:ftp/curl
TEST_DEPENDS=	bash:shells/bash

USES=		cmake:insource,testing localbase:ldflags # tests fail in outsource build, see https://github.com/veg/hyphy/issues/1528

USE_GITHUB=	yes
GH_ACCOUNT=	veg

OPTIONS_DEFINE=		AVX TARGET_NATIVE
AVX_DESC=		Advanced vector extensions support
TARGET_NATIVE_DESC=	Enable CPU-specific instructions and tuning for build machine

AVX_CMAKE_BOOL_OFF=		NOAVX
TARGET_NATIVE_CMAKE_BOOL=	TARGET_NATIVE

.include <bsd.port.mk>
