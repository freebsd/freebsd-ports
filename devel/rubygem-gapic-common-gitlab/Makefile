PORTNAME=	gapic-common
PORTVERSION=	0.23.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Common code for GAPIC-generated API clients
WWW=		https://github.com/googleapis/gapic-generator-ruby/tree/master/gapic-common \
		https://github.com/googleapis/gapic-generator-ruby

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-faraday-gitlab>=1.9<3:www/rubygem-faraday-gitlab \
		rubygem-faraday-retry-gitlab>=1.0<3:www/rubygem-faraday-retry-gitlab \
		rubygem-google-protobuf>=3.25<5.0:devel/rubygem-google-protobuf \
		rubygem-googleapis-common-protos-gitlab>=1.6<2:devel/rubygem-googleapis-common-protos-gitlab \
		rubygem-googleapis-common-protos-types>=1.15<2:devel/rubygem-googleapis-common-protos-types \
		rubygem-googleauth-gitlab>=1.11<2:security/rubygem-googleauth-gitlab \
		rubygem-grpc-gitlab>=1.65<2:net/rubygem-grpc-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
