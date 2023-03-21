PORTNAME=	google-iam-credentials
PORTVERSION=	1.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the IAM Policy API
WWW=		https://github.com/googleapis/google-cloud-ruby/tree/main/google-iam-credentials

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-cloud-core>=1.6<2:net/rubygem-google-cloud-core \
		rubygem-google-iam-credentials-v1>=0.3<2.0:devel/rubygem-google-iam-credentials-v1

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
