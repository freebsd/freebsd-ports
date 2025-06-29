PORTNAME=	aws-sdk-efs
PORTVERSION=	1.96.0
CATEGORIES=	devel filesystems rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official AWS Ruby gem for Amazon Elastic File System (EFS)
WWW=		https://github.com/aws/aws-sdk-ruby/tree/version-3/gems/aws-sdk-efs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-sdk-core>=3.225.0<4:devel/rubygem-aws-sdk-core \
		rubygem-aws-sigv4>=1.5<2:devel/rubygem-aws-sigv4

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
