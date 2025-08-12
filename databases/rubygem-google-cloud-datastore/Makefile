PORTNAME=	google-cloud-datastore
PORTVERSION=	2.13.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Google Cloud Datastore
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-datastore/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-datastore \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-google-cloud-core>=1.5<2:net/rubygem-google-cloud-core \
		rubygem-google-cloud-datastore-v1>=0.0<2.0:databases/rubygem-google-cloud-datastore-v1

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
