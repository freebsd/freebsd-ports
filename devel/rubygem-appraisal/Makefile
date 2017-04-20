# $FreeBSD$

PORTNAME=	appraisal
PORTVERSION=	2.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Integrates with bundler and rake to test library dependencies

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake \
		rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-thor>=0.14.0:devel/rubygem-thor \
		rubygem-activesupport5>0:devel/rubygem-activesupport5 \
		rubygem-rspec>=3.0:devel/rubygem-rspec

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/appraisal

.include <bsd.port.mk>
