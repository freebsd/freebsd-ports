PORTNAME=	span
PORTVERSION=	0.0.0.g20220615
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of C++20's std::span for older compilers
WWW=		https://github.com/tcbrindle/span

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/tcb/span.hpp

USE_GITHUB=	yes
GH_ACCOUNT=	tcbrindle
GH_TAGNAME=	836dc6a

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tcb/
	${INSTALL_DATA} ${WRKSRC}/include/tcb/span.hpp ${STAGEDIR}${PREFIX}/include/tcb/span.hpp

.include <bsd.port.mk>
