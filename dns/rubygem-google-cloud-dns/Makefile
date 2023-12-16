PORTNAME=	google-cloud-dns
PORTVERSION=	0.36.1
CATEGORIES=	dns rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Google Cloud DNS
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-dns/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-dns \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-google-apis-dns_v1>=0.1<1:dns/rubygem-google-apis-dns_v1 \
		rubygem-google-cloud-core>=1.6<2:net/rubygem-google-cloud-core \
		rubygem-googleauth>=0.16.2<2.0:security/rubygem-googleauth \
		rubygem-zonefile>=1.04<2:dns/rubygem-zonefile

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
