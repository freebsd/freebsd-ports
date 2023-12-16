PORTNAME=	google-cloud-datastore-v1
PORTVERSION=	0.14.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the Firestore in Datastore mode V1 API
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-datastore-v1/latest/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-datastore-v1 \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-gapic-common>=0.20.0<2.0:devel/rubygem-gapic-common \
		rubygem-google-cloud-errors>=1.0<2:net/rubygem-google-cloud-errors

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
