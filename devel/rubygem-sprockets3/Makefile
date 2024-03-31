PORTNAME=	sprockets
PORTVERSION=	3.7.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby library that preprocesses and concatenates JavaScript files
WWW=		https://github.com/rails/sprockets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-rack22>=1,3<3,3:www/rubygem-rack22

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	sprockets_project

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/sprockets

.include <bsd.port.mk>
