PORTNAME=	cucumber
PORTVERSION=	6.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour Driven Development with elegance and joy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=3.2.4<4:devel/rubygem-builder \
		rubygem-cucumber-core>=9.0.0<10:devel/rubygem-cucumber-core \
		rubygem-cucumber-create-meta>=4.0.0<5:devel/rubygem-cucumber-create-meta \
		rubygem-cucumber-cucumber-expressions>=12.1.1<13:devel/rubygem-cucumber-cucumber-expressions \
		rubygem-cucumber-gherkin>=18.1.0<19:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-html-formatter>=13.0.0<14:textproc/rubygem-cucumber-html-formatter \
		rubygem-cucumber-messages>=15.0.0<16:devel/rubygem-cucumber-messages \
		rubygem-cucumber-wire>=5.0.0<6:devel/rubygem-cucumber-wire \
		rubygem-diff-lcs>=1.4.4<2:textproc/rubygem-diff-lcs \
		rubygem-mime-types>=3.3.1<4:misc/rubygem-mime-types \
		rubygem-multi_test>=0.1.2<1:devel/rubygem-multi_test \
		rubygem-sys-uname>=1.2.2<2:sysutils/rubygem-sys-uname

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber

.include <bsd.port.mk>
