# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-gax
PORTVERSION=	1.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google API Extensions

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	rubygem-google-protobuf>=3.2<4:devel/rubygem-google-protobuf \
		rubygem-googleapis-common-protos>=1.3.5<2.0:devel/rubygem-googleapis-common-protos \
		rubygem-googleauth>=0.6.2<0.10.0:security/rubygem-googleauth \
		rubygem-grpc>=1.7.2<2.0:net/rubygem-grpc \
		rubygem-rly>=0.2.3<0.3:textproc/rubygem-rly

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
