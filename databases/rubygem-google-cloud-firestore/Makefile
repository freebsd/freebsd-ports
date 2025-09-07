PORTNAME=	google-cloud-firestore
PORTVERSION=	3.1.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Google Cloud Firestore API
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-firestore/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-firestore \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bigdecimal>=3.0<4:math/rubygem-bigdecimal \
		rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-google-cloud-core>=1.7<2:net/rubygem-google-cloud-core \
		rubygem-google-cloud-firestore-v1>=2.0<3:databases/rubygem-google-cloud-firestore-v1 \
		rubygem-rbtree>=0.4.2<0.5:devel/rubygem-rbtree

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
