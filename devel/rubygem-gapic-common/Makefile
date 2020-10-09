# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gapic-common
PORTVERSION=	0.3.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common code for GAPIC-generated API clients

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-google-protobuf>=3.12<4:devel/rubygem-google-protobuf \
		rubygem-googleapis-common-protos>=1.3.9<2.0:devel/rubygem-googleapis-common-protos \
		rubygem-googleapis-common-protos-types>=1.0.4<2.0:devel/rubygem-googleapis-common-protos-types \
		rubygem-googleauth>=0.9<1:security/rubygem-googleauth \
		rubygem-grpc>=1.25<2:net/rubygem-grpc

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
