PORTNAME=	googleapis-common-protos
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Common gRPC and protocol buffer classes used in Google APIs
WWW=		https://github.com/googleapis/common-protos-ruby/tree/main/googleapis-common-protos \
		https://github.com/googleapis/common-protos-ruby

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-google-protobuf-gitlab>=3.18<5.0:devel/rubygem-google-protobuf-gitlab \
		rubygem-googleapis-common-protos-types-gitlab>=1.20<2:devel/rubygem-googleapis-common-protos-types-gitlab \
		rubygem-grpc-gitlab>=1.41<2:net/rubygem-grpc-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
