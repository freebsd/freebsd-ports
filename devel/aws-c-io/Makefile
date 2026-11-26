PORTNAME=	aws-c-io
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Event driven framework for implementing application protocols
WWW=		https://github.com/awslabs/aws-c-io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaws-c-cal.so:security/aws-c-cal \
		libaws-c-common.so:devel/aws-c-common \
		libs2n.so:security/s2n-tls

USES=		cmake:testing cpe localbase ssl
USE_GITHUB=	yes
GH_ACCOUNT=	awslabs
USE_LDCONFIG=	yes

CPE_VENDOR=	amazon
CPE_PRODUCT=	amazon_web_services_aws-c-io

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

PLIST_SUB=	SOVERSION=${DISTVERSION} \
		SOVERSION_R=${DISTVERSION:R}

.include <bsd.port.mk>
