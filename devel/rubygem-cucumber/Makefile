# $FreeBSD$

PORTNAME=	cucumber
PORTVERSION=	3.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Behaviour Driven Development with elegance and joy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=2.1.2:devel/rubygem-builder \
		rubygem-cucumber-core>=3.0.0:devel/rubygem-cucumber-core \
		rubygem-cucumber-expressions>=4.0.3:devel/rubygem-cucumber-expressions \
		rubygem-cucumber-wire>=0.0.1:devel/rubygem-cucumber-wire \
		rubygem-diff-lcs>=1.3:textproc/rubygem-diff-lcs \
		rubygem-gherkin>=4.0:textproc/rubygem-gherkin \
		rubygem-multi_json>=1.7.5:devel/rubygem-multi_json \
		rubygem-multi_test>=0.1.2:devel/rubygem-multi_test

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/cucumber

.include <bsd.port.mk>
