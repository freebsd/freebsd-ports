PORTNAME=	aws-sdk-sso
PORTVERSION=	1.12.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official AWS Ruby gem for AWS Single Sign-On (SSO)
WWW=		https://github.com/aws/aws-sdk-ruby/tree/version-3/gems/aws-sdk-sso

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	SSO is included as part of aws-sdk-core. Use devel/rubygem-aws-sdk-core instead
EXPIRATION_DATE=2023-12-31

RUN_DEPENDS=	rubygem-aws-sdk-core>=3.105.0<4:devel/rubygem-aws-sdk-core \
		rubygem-aws-sigv4>=1.1<2:devel/rubygem-aws-sigv4

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
