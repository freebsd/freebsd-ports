PORTNAME=	cucumber
PORTVERSION=	7.1.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour Driven Development with elegance and joy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=3.2.4<4:devel/rubygem-builder \
		rubygem-cucumber-core>=10.1.0<11:devel/rubygem-cucumber-core \
		rubygem-cucumber-create-meta>=6.0.1<7:devel/rubygem-cucumber-create-meta \
		rubygem-cucumber-cucumber-expressions>=14.0.0<15:devel/rubygem-cucumber-cucumber-expressions \
		rubygem-cucumber-gherkin>=22.0.0<23:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-html-formatter17>=17.0.0<18:textproc/rubygem-cucumber-html-formatter17 \
		rubygem-cucumber-messages>=17.1.1<18:devel/rubygem-cucumber-messages \
		rubygem-cucumber-wire>=6.2.0<7:devel/rubygem-cucumber-wire \
		rubygem-diff-lcs>=1.4.4<2:textproc/rubygem-diff-lcs \
		rubygem-mime-types>=3.3.1<4:misc/rubygem-mime-types \
		rubygem-multi_test>=0.1.2<1:devel/rubygem-multi_test \
		rubygem-sys-uname>=1.2.2<2:sysutils/rubygem-sys-uname

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber

.include <bsd.port.mk>
