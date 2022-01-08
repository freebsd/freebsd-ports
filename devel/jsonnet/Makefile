# Created by: Gasol Wu <gasol.wu@gmail.com>

PORTNAME=	jsonnet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	JSON data templating language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>=3.6.1:devel/nlohmann-json
LIB_DEPENDS=	libc4core.so:devel/c4core \
		libryml.so:devel/rapidyaml

USES=		compiler:c++11-lib cmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	google

USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_JSONNET BUILD_JSONNETFMT BUILD_STATIC_LIBS \
		BUILD_SHARED_BINARIES USE_SYSTEM_JSON
CMAKE_OFF=	BUILD_TESTS

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
