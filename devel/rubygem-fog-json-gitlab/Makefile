PORTNAME=	fog-json
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Extraction of the JSON parsing tools between providers
WWW=		https://github.com/fog/fog-json

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core-gitlab>=0:devel/rubygem-fog-core-gitlab \
		rubygem-multi_json-gitlab>=1.10<2:devel/rubygem-multi_json-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
