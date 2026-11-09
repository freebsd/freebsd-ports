PORTNAME=	libgraphqlparser
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GraphQL query parser
WWW=		https://github.com/graphql/libgraphqlparser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bison cmake compiler:c++11-lang python:build

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

USE_GITHUB=	yes
GH_ACCOUNT=	graphql

.include <bsd.port.mk>
