PORTNAME=	google-cloud-firestore-v1
PORTVERSION=	0.10.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the Cloud Firestore V1 API
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-firestore-v1/latest/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-firestore-v1 \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-gapic-common>=0.17.1<2.0:devel/rubygem-gapic-common \
		rubygem-google-cloud-errors>=1.0<2:net/rubygem-google-cloud-errors \
		rubygem-google-cloud-location>=0.4<2.0:net/rubygem-google-cloud-location

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
