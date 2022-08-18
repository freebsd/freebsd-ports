PORTNAME=	open62541
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.3
CATEGORIES=	devel

MAINTAINER=	nsonack@outlook.com
COMMENT=	Open source implementation of OPC UA

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake python shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
SHEBANG_GLOB=	*.py
BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	${RMDIR} ${STAGEDIR}${DATADIR}/tools/ua-nodeset
	${RMDIR} ${STAGEDIR}${DATADIR}/tools/nodeset_compiler/__pycache__

.include <bsd.port.mk>
