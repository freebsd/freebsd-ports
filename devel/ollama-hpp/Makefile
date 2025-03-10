PORTNAME=	ollama-hpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.4
CATEGORIES=	devel # machine learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern, Header-only C++ bindings for the Ollama API
WWW=		https://github.com/kongaskristjan/fire-hpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	jmont-dev

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/ollama.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/singleheader/ollama.hpp ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
