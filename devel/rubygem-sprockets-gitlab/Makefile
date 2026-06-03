PORTNAME=	sprockets
PORTVERSION=	3.7.5
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby library that preprocesses and concatenates JavaScript files
WWW=		https://github.com/rails/sprockets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-rack-gitlab>=1<3:www/rubygem-rack-gitlab

USES=		cpe gem

CPE_VENDOR=	sprockets_project

NO_ARCH=	yes

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/sprockets

.include <bsd.port.mk>
