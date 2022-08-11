PORTNAME=	cucumber
PORTVERSION=	8.0.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour Driven Development with elegance and joy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=3.2.4<4:devel/rubygem-builder \
		rubygem-cucumber-ci-environment>=9.0.4<10:devel/rubygem-cucumber-ci-environment \
		rubygem-cucumber-core>=11.0.0<12:devel/rubygem-cucumber-core \
		rubygem-cucumber-cucumber-expressions15>=15.1.1<16:devel/rubygem-cucumber-cucumber-expressions15 \
		rubygem-cucumber-gherkin23>=23.0.1<24:textproc/rubygem-cucumber-gherkin23 \
		rubygem-cucumber-html-formatter>=19.1.0<20:textproc/rubygem-cucumber-html-formatter \
		rubygem-cucumber-messages18>=18.0.0<19:devel/rubygem-cucumber-messages18 \
		rubygem-diff-lcs>=1.5.0<2:textproc/rubygem-diff-lcs \
		rubygem-mime-types>=3.4.1<4:misc/rubygem-mime-types \
		rubygem-multi_test>=1.1.0<2:devel/rubygem-multi_test \
		rubygem-sys-uname>=1.2.2<2:sysutils/rubygem-sys-uname

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber

.include <bsd.port.mk>
