PORTNAME=	aws-sdk-core
PORTVERSION=	3.172.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3172

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AWS SDK for Ruby - Core
WWW=		https://github.com/aws/aws-sdk-ruby/tree/version-3/gems/aws-sdk-core

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-eventstream>=1.0.2<2:devel/rubygem-aws-eventstream \
		rubygem-aws-partitions>=1.651.0<2:devel/rubygem-aws-partitions \
		rubygem-aws-sigv4>=1.5<2:devel/rubygem-aws-sigv4 \
		rubygem-jmespath>=1.6.1<2:devel/rubygem-jmespath

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.172\.

.include <bsd.port.mk>
