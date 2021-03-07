# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gapic-common
PORTVERSION=	0.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common code for GAPIC-generated API clients

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-faraday>=1.3<2:www/rubygem-faraday \
		rubygem-google-protobuf>=3.15.2<4:devel/rubygem-google-protobuf \
		rubygem-googleapis-common-protos>=1.3.11<2.0:devel/rubygem-googleapis-common-protos \
		rubygem-googleapis-common-protos-types>=1.0.6<2.0:devel/rubygem-googleapis-common-protos-types \
		rubygem-googleauth>=0.15.1<1:security/rubygem-googleauth \
		rubygem-grpc>=1.36<2:net/rubygem-grpc

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
