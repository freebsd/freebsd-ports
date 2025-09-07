PORTNAME=	gapic-common
PORTVERSION=	1.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common code for GAPIC-generated API clients
WWW=		https://github.com/googleapis/ruby-core-libraries/tree/main/gapic-common \
		https://github.com/googleapis/ruby-core-libraries

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-faraday>=1.9<3:www/rubygem-faraday \
		rubygem-faraday-retry>=1.0<3:www/rubygem-faraday-retry \
		rubygem-google-cloud-env>=2.2<3:net/rubygem-google-cloud-env \
		rubygem-google-logging-utils>=0.1<1:devel/rubygem-google-logging-utils \
		rubygem-google-protobuf>=3.25<5.0:devel/rubygem-google-protobuf \
		rubygem-googleapis-common-protos>=1.6<2:devel/rubygem-googleapis-common-protos \
		rubygem-googleapis-common-protos-types>=1.15<2:devel/rubygem-googleapis-common-protos-types \
		rubygem-googleauth>=1.12<2:security/rubygem-googleauth \
		rubygem-grpc>=1.66<2:net/rubygem-grpc

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
