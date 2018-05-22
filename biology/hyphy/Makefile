# $FreeBSD$

PORTNAME=	hyphy
DISTVERSION=	2.3.13
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Hypothesis testing using Phylogenies

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		compiler:c++14-lang cmake:outsource localbase:ldflags ssl
USE_GITHUB=	yes
GH_ACCOUNT=	veg

.include <bsd.port.mk>
