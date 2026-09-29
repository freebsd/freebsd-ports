PORTNAME=	fog-json
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extraction of the JSON parsing tools between providers
WWW=		https://github.com/fog/fog-json

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core>=0:devel/rubygem-fog-core \
		rubygem-json2>=2.19<3:devel/rubygem-json2

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
