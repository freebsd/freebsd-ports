# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-cloud-dns
PORTVERSION=	0.33.0
CATEGORIES=	dns rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Google Cloud DNS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-google-api-client>=0.33<1:devel/rubygem-google-api-client \
		rubygem-google-cloud-core>=1.2<2:net/rubygem-google-cloud-core \
		rubygem-googleauth>=0.9<1:security/rubygem-googleauth \
		rubygem-zonefile>=1.04<2:dns/rubygem-zonefile

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
