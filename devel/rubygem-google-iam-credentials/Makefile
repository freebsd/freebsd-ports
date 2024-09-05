PORTNAME=	google-iam-credentials
PORTVERSION=	1.4.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the IAM Policy API
WWW=		https://cloud.google.com/ruby/docs/reference/google-iam-credentials/latest/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-iam-credentials \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-cloud-core>=1.6<2:net/rubygem-google-cloud-core \
		rubygem-google-iam-credentials-v1>=0.8<2.0:devel/rubygem-google-iam-credentials-v1

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
