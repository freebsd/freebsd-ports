PORTNAME=	jsonnet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
CATEGORIES=	devel
# It is necessary to synchronize RY_VERSION with devel/rapidyaml port:
RY_VERSION=	0.9.0
RY_FILE=	rapidyaml-${RY_VERSION}.hpp
MASTER_SITES=	https://github.com/biojppm/rapidyaml/releases/download/v${RY_VERSION}/:rapidyaml
DISTFILES+=	${RY_FILE}:rapidyaml
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

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

CMAKE_ON=	BUILD_JSONNET BUILD_JSONNETFMT BUILD_STATIC_LIBS \
		BUILD_SHARED_BINARIES USE_SYSTEM_JSON
CMAKE_OFF=	BUILD_TESTS

PLIST_SUB=	VERSION=${DISTVERSION}

post-extract:
	${CP} ${DISTDIR}/${RY_FILE} ${WRKSRC}/third_party/rapidyaml/ryml_all.hpp

.include <bsd.port.mk>
