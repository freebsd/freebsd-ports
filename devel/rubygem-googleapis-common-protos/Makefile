PORTNAME=	googleapis-common-protos
PORTVERSION=	1.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common gRPC and protocol buffer classes used in Google APIs
WWW=		https://github.com/googleapis/common-protos-ruby/tree/main/googleapis-common-protos

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-google-protobuf>=3.14<4:devel/rubygem-google-protobuf \
		rubygem-googleapis-common-protos-types>=1.2<2:devel/rubygem-googleapis-common-protos-types \
		rubygem-grpc>=1.27<2:net/rubygem-grpc

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
