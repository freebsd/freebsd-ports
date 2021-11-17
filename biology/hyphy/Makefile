PORTNAME=	hyphy
DISTVERSION=	2.5.33
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Hypothesis testing using Phylogenies

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386 powerpc64le powerpc64 powerpc

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	veg

OPTIONS_DEFINE=	AVX
AVX_DESC=	Advanced vector extensions support

AVX_CMAKE_OFF=	-DNOAVX:BOOL=ON

.include <bsd.port.mk>
