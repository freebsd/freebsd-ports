PORTNAME=	blend2d
DISTVERSION=	g20200108
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	2D Vector Graphics Engine Powered by a JIT Compiler

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libasmjit.so:devel/asmjit

USES=		cmake localbase
USE_GITHUB=	yes
GH_TAGNAME=	592d1ba52672bbf6365aba476bfe26b7bd2dfab8
USE_LDCONFIG=	yes

LDFLAGS+=	${LOCALBASE}/lib/libasmjit.so # see https://github.com/blend2d/blend2d/issues/57

.include <bsd.port.mk>
