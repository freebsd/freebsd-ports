PORTNAME=	argtable3
DISTVERSION=	3.2.2
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	ANSI C library that parses GNU-style command-line options
WWW=		https://www.argtable.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash>0:shells/bash

USES=		cmake compiler:c++11-lang shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	argtable
GH_TAGNAME=	f319bb66252c6d32a0657c774534ba409567aa62

SHEBANG_FILES=	${WRKSRC}/tools/build

post-patch:
	${REINPLACE_CMD} '66d' ${WRKSRC}/tools/build

.include <bsd.port.mk>
