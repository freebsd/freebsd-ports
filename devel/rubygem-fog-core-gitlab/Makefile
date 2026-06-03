PORTNAME=	fog-core
PORTVERSION=	2.6.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Shared classes and tests for fog providers and services
WWW=		https://github.com/fog/fog-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-builder>=0:devel/rubygem-builder \
		rubygem-excon-gitlab>=1<2:devel/rubygem-excon-gitlab \
		rubygem-formatador>=0.2<2.0:devel/rubygem-formatador \
		rubygem-mime-types-gitlab>=0:misc/rubygem-mime-types-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
