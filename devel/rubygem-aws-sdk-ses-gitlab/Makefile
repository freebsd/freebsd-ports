PORTNAME=	aws-sdk-ses
PORTVERSION=	1.101.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Official AWS Ruby gem for Amazon Simple Email Service (Amazon SES)
WWW=		https://github.com/aws/aws-sdk-ruby/tree/version-3/gems/aws-sdk-ses

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-sdk-core-gitlab>=3.248.0<4:devel/rubygem-aws-sdk-core-gitlab \
		rubygem-aws-sigv4>=1.5<2:devel/rubygem-aws-sigv4

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
