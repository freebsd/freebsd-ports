# $FreeBSD$

PORTNAME=	cucumber
PORTVERSION=	2.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Behaviour Driven Development with elegance and joy

LICENSE=	MIT

RUN_DEPENDS=	rubygem-builder32>=2.1.2:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-cucumber-core>=1.1.3:${PORTSDIR}/devel/rubygem-cucumber-core \
		rubygem-diff-lcs>=1.1.3:${PORTSDIR}/textproc/rubygem-diff-lcs \
		rubygem-gherkin>=2.12:${PORTSDIR}/textproc/rubygem-gherkin \
		rubygem-multi_json>=1.7.5:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-multi_test>=0.1.2:${PORTSDIR}/devel/rubygem-multi_test

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/cucumber

.include <bsd.port.mk>
