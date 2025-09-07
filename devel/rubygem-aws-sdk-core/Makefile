PORTNAME=	aws-sdk-core
PORTVERSION=	3.232.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AWS SDK for Ruby - Core
WWW=		https://github.com/aws/aws-sdk-ruby/tree/version-3/gems/aws-sdk-core

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-eventstream>=1.3.0<2:devel/rubygem-aws-eventstream \
		rubygem-aws-partitions>=1.992.0<2:devel/rubygem-aws-partitions \
		rubygem-aws-sigv4>=1.9<2:devel/rubygem-aws-sigv4 \
		rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-bigdecimal>=0:math/rubygem-bigdecimal \
		rubygem-jmespath>=1.6.1<2:devel/rubygem-jmespath \
		rubygem-logger>=0:devel/rubygem-logger

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
