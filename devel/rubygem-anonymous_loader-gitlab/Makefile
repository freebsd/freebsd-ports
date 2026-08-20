PORTNAME=	anonymous_loader
PORTVERSION=	0.1.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Resolve Ruby files and evaluate them to avoid top-level namespace collisions
WWW=		https://anonymous-loader.galtzo.com/ \
		https://github.com/ruby-oauth/anonymous_loader

LICENSE=	MIT
#LICENSE_FILE=	${WRKSRC}/MIT.md

RUN_DEPENDS=	rubygem-version_gem-gitlab>=1.1.14<2:devel/rubygem-version_gem-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
