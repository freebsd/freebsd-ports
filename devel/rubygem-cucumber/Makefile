# $FreeBSD$

PORTNAME=	cucumber
PORTVERSION=	4.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour Driven Development with elegance and joy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=3.2.3<4:devel/rubygem-builder \
		rubygem-cucumber-core>=7.0.0<8:devel/rubygem-cucumber-core \
		rubygem-cucumber-cucumber-expressions>=10.1.0<11:devel/rubygem-cucumber-cucumber-expressions \
		rubygem-cucumber-gherkin>=13.0.0<14:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-html-formatter>=6.0.1<7:textproc/rubygem-cucumber-html-formatter \
		rubygem-cucumber-messages>=12.1.1<13:devel/rubygem-cucumber-messages \
		rubygem-cucumber-wire>=3.0.0<4:devel/rubygem-cucumber-wire \
		rubygem-diff-lcs>=1.3<2:textproc/rubygem-diff-lcs \
		rubygem-multi_test>=0.1.2<1:devel/rubygem-multi_test \
		rubygem-sys-uname>=1.0.2<2:sysutils/rubygem-sys-uname

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber

.include <bsd.port.mk>
