# $FreeBSD$

PORTNAME=	hyphy
DISTVERSION=	2.5.7
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Hypothesis testing using Phylogenies

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		compiler:openmp cmake localbase:ldflags ssl
USE_GITHUB=	yes
GH_ACCOUNT=	veg

CMAKE_ON=	NOAVX

.include <bsd.port.mk>
