PORTNAME=	websocketpp
PORTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	sigsegv@radiotube.org
COMMENT=	Header-only implementation of the WebSocket protocol
WWW=		https://www.zaphoyd.com/websocketpp/

LICENSE=	MIT BSD3CLAUSE ZLIB
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake:insource,testing cpe
CPE_VENDOR=	zaphoyd
USE_GITHUB=	yes
GH_ACCOUNT=	zaphoyd

CMAKE_TESTING_ON=	BUILD_TESTS

NO_ARCH=	yes

post-stage: # https://github.com/zaphoyd/websocketpp/issues/781
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/websocketpp/CMakeFiles

.include <bsd.port.mk>
