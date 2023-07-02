PORTNAME=	aws-sdk-s3
PORTVERSION=	1.126.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1126

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Official AWS Ruby gem for Amazon Simple Storage Service (Amazon S3)
WWW=		https://github.com/aws/aws-sdk-ruby/tree/version-3/gems/aws-sdk-s3

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-sdk-core3175>=3.174.0<4:devel/rubygem-aws-sdk-core3175 \
		rubygem-aws-sdk-kms>=1<2:devel/rubygem-aws-sdk-kms \
		rubygem-aws-sigv4>=1.4<2:devel/rubygem-aws-sigv4

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.126\.

.include <bsd.port.mk>
