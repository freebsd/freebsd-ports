# $FreeBSD$

PORTNAME=	appraisal
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Integrates with bundler and rake to test library dependencies

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-rake>=0:devel/rubygem-rake \
		rubygem-thor>=0.14.0:devel/rubygem-thor

USE_RUBY=	yes
USES=		gem
NO_ARCH=	yes

PLIST_FILES=	bin/appraisal

.include <bsd.port.mk>
