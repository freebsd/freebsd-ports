PORTNAME=	iniparser
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.4
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Free stand-alone ini file parsing library
WWW=		https://github.com/ndevilla/iniparser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake pathfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ndevilla

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CMAKE_BOOL=	BUILD_DOCS

.include <bsd.port.mk>
