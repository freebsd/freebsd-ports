# $FreeBSD$

PORTNAME=	cucumber
PORTVERSION=	5.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour Driven Development with elegance and joy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=3.2.4<4:devel/rubygem-builder \
		rubygem-cucumber-core>=8.0.1<9:devel/rubygem-cucumber-core \
		rubygem-cucumber-create-meta>=2.0.2<3:devel/rubygem-cucumber-create-meta \
		rubygem-cucumber-cucumber-expressions>=10.3.0<11:devel/rubygem-cucumber-cucumber-expressions \
		rubygem-cucumber-gherkin>=15.0.2<16:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-html-formatter>=9.0.0<10:textproc/rubygem-cucumber-html-formatter \
		rubygem-cucumber-messages>=13.1.0<14:devel/rubygem-cucumber-messages \
		rubygem-cucumber-wire>=4.0.1<5:devel/rubygem-cucumber-wire \
		rubygem-diff-lcs>=1.4.4<2:textproc/rubygem-diff-lcs \
		rubygem-multi_test>=0.1.2<1:devel/rubygem-multi_test \
		rubygem-sys-uname>=1.2.1<2:sysutils/rubygem-sys-uname

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber

.include <bsd.port.mk>
