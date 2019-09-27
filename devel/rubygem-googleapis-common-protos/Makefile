# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googleapis-common-protos
PORTVERSION=	1.3.9
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common gRPC and protocol buffer classes used in Google APIs

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-google-protobuf>=3.0<4:devel/rubygem-google-protobuf \
		rubygem-googleapis-common-protos-types>=1.0<2:devel/rubygem-googleapis-common-protos-types \
		rubygem-grpc>=1.0<2:net/rubygem-grpc

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
