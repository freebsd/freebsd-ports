PORTNAME=	jsonnet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.22.0
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	JSON data templating language
WWW=		https://jsonnet.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>=3.6.1:devel/nlohmann-json
LIB_DEPENDS=	libc4core.so:devel/c4core \
		libryml.so:devel/rapidyaml

USES=		compiler:c++17-lang cmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	google

USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_JSONNET BUILD_JSONNETFMT BUILD_SHARED_BINARIES \
		BUILD_SHARED_LIBS BUILD_STATIC_LIBS USE_SYSTEM_JSON \
		USE_SYSTEM_RAPIDYAML
CMAKE_OFF=	BUILD_MAN_PAGES BUILD_TESTS

PLIST_SUB=	VERSION=${DISTVERSION}

.include <bsd.port.mk>
