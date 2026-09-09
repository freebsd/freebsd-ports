PORTNAME=	unleash
PORTVERSION=	5.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby client for Unleash
WWW=		https://www.getunleash.io/ \
		https://github.com/Unleash/unleash-ruby-sdk

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-murmurhash3>=0.1.7<0.2:devel/rubygem-murmurhash3

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/unleash-client

.include <bsd.port.mk>
