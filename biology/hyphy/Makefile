PORTNAME=	hyphy
DISTVERSION=	2.5.43
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Hypothesis testing using Phylogenies
WWW=		https://www.hyphy.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386 powerpc powerpc64 powerpc64le

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake:insource,testing localbase:ldflags # tests fail in outsource build, see https://github.com/veg/hyphy/issues/1528

USE_GITHUB=	yes
GH_ACCOUNT=	veg

OPTIONS_DEFINE=	AVX
AVX_DESC=	Advanced vector extensions support

AVX_CMAKE_OFF=	-DNOAVX:BOOL=ON

# 2 tests fail, see https://github.com/veg/hyphy/issues/1529

.include <bsd.port.mk>
