PORTNAME=	iceoryx
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	comms

MAINTAINER=	flo@purplekraken.com
COMMENT=	True zero-copy inter-process communication

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	upstream supports only 64-bit hardware

BUILD_DEPENDS=	cpptoml>=0.1.1:textproc/cpptoml

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	eclipse-iceoryx

USE_LDCONFIG=	yes

CMAKE_ON=	BINDING_C BUILD_SHARED_LIBS
CMAKE_OFF=	DOWNLOAD_TOML_LIB
CMAKE_SOURCE_PATH=	${WRKSRC}/iceoryx_meta

PLIST_SUB=	VERSION=${GH_TAGNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
