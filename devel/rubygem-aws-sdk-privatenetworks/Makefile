PORTNAME=	aws-sdk-privatenetworks
PORTVERSION=	1.13.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official AWS Ruby gem for AWS Private 5G
WWW=		https://github.com/aws/aws-sdk-ruby/tree/version-3/gems/aws-sdk-privatenetworks

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-sdk-core>=3.188.0<4:devel/rubygem-aws-sdk-core \
		rubygem-aws-sigv4>=1.1<2:devel/rubygem-aws-sigv4

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
