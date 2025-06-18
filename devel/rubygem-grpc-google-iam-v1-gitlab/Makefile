PORTNAME=	grpc-google-iam-v1
PORTVERSION=	1.11.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Common protos and gRPC services for Google IAM
WWW=		https://github.com/googleapis/common-protos-ruby/tree/main/grpc-google-iam-v1 \
		https://github.com/googleapis/common-protos-ruby

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-google-protobuf>=3.18<5.0:devel/rubygem-google-protobuf \
		rubygem-googleapis-common-protos-gitlab>=1.7.0<2:devel/rubygem-googleapis-common-protos-gitlab \
		rubygem-grpc-gitlab>=1.41<2:net/rubygem-grpc-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
