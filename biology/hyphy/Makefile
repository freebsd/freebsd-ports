# $FreeBSD$

PORTNAME=	hyphy
DISTVERSION=	2.5.28
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Hypothesis testing using Phylogenies

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake localbase:ldflags ssl
USE_GITHUB=	yes
GH_ACCOUNT=	veg

OPTIONS_DEFINE=	AVX
AVX_DESC=	Advanced vector extensions support

AVX_CMAKE_OFF=	-DNOAVX:BOOL=ON

.include <bsd.port.mk>
