PORTNAME=	aws-sdk-core
PORTVERSION=	3.113.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AWS SDK for Ruby - Core

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-eventstream>=1.0.2<2:devel/rubygem-aws-eventstream \
		rubygem-aws-partitions>=1.239.0<2:devel/rubygem-aws-partitions \
		rubygem-aws-sigv4>=1.1<2:devel/rubygem-aws-sigv4 \
		rubygem-jmespath>=1.0<2:devel/rubygem-jmespath

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
