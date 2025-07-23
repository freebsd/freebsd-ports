PORTNAME=	CycloneDDS
DISTVERSION=	0.10.5
CATEGORIES=	comms

MAINTAINER=	flo@purplekraken.com
COMMENT=	Eclipse Cyclone DDS middleware
WWW=		https://cyclonedds.io/ \
		https://github.com/eclipse-cyclonedds/cyclonedds/

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libiceoryx_binding_c.so:comms/iceoryx

USES=		bison cmake

USE_GITHUB=	yes
GH_ACCOUNT=	eclipse-cyclonedds
GH_PROJECT=	cyclonedds

USE_LDCONFIG=	yes

CMAKE_ON=	ENABLE_SHM

OPTIONS_DEFINE=		DOCS SSL TEST
OPTIONS_DEFAULT=	SSL

SSL_DESC=	Enable SSL support
TEST_DESC=	Build tests

SSL_USES=		ssl
SSL_CMAKE_BOOL=		ENABLE_SSL
TEST_LIB_DEPENDS=	libcunit.so:devel/cunit
TEST_CMAKE_BOOL=	BUILD_TESTING

.include <bsd.port.mk>
