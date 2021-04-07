PORTNAME=	tlx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.20200222-5
DISTVERSIONSUFFIX=	-g8982a9d
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of C++ data structures, algorithms, miscellaneous helpers

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	TLX_BUILD_SHARED_LIBS

.include <bsd.port.mk>
