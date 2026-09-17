PORTNAME=	iniparser
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.0
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Free stand-alone ini file parsing library
WWW=		https://github.com/ndevilla/iniparser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${RUBY}:${RUBY_PORT}

USES=		cmake:testing cpe pathfix ruby:none
CPE_VENDOR=	ndevilla
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ndevilla

GH_TUPLE=	ThrowTheSwitch:Unity:v2.7.0:unity/unity
CMAKE_TESTING_ARGS=	-DFETCHCONTENT_SOURCE_DIR_UNITY=${WRKSRC}/unity

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CMAKE_BOOL=	BUILD_DOCS

pre-test:
	@${CP} ${WRKSRC}/test/unity_config.h ${WRKSRC}/unity/src/

.include <bsd.port.mk>
