PORTNAME=	google-cloud-firestore-v1
PORTVERSION=	2.1.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the Cloud Firestore V1 API
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-firestore-v1/latest/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-firestore-v1 \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-gapic-common>=1.0<2:devel/rubygem-gapic-common \
		rubygem-google-cloud-errors>=1.0<2:net/rubygem-google-cloud-errors \
		rubygem-google-cloud-location>=1.0<2:net/rubygem-google-cloud-location

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
