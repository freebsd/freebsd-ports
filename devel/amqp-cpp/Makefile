PORTNAME=	amqp-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.4
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	aleksandr.fedorov@vstack.com
COMMENT=	C++ library for asynchronous non-blocking communication with RabbitMQ

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

CMAKE_ON=	AMQP-CPP_LINUX_TCP AMQP-CPP_BUILD_SHARED

USE_GITHUB=	yes
GH_ACCOUNT=	CopernicaMarketingSoftware
GH_PROJECT=	AMQP-CPP

.include <bsd.port.mk>
