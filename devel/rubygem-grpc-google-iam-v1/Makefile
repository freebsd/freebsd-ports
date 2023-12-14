PORTNAME=	grpc-google-iam-v1
PORTVERSION=	1.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common protos and gRPC services for Google IAM
WWW=		https://github.com/googleapis/common-protos-ruby/tree/main/grpc-google-iam-v1 \
		https://github.com/googleapis/common-protos-ruby

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-google-protobuf>=3.18<4:devel/rubygem-google-protobuf \
		rubygem-googleapis-common-protos>=1.4<2:devel/rubygem-googleapis-common-protos \
		rubygem-grpc>=1.41<2:net/rubygem-grpc

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
