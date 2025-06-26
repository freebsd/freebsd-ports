PORTNAME=	cucumber
PORTVERSION=	9.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	9

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour Driven Development with elegance and joy
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=3.2<4:devel/rubygem-builder \
		rubygem-cucumber-ci-environment>=9<11:devel/rubygem-cucumber-ci-environment \
		rubygem-cucumber-core13>=13<14:devel/rubygem-cucumber-core13 \
		rubygem-cucumber-cucumber-expressions17>=17.0<18:devel/rubygem-cucumber-cucumber-expressions17 \
		rubygem-cucumber-gherkin27>=24<28:textproc/rubygem-cucumber-gherkin27 \
		rubygem-cucumber-html-formatter>=20.3<22:textproc/rubygem-cucumber-html-formatter \
		rubygem-cucumber-messages24>=19<25:devel/rubygem-cucumber-messages24 \
		rubygem-diff-lcs>=1.5<2:textproc/rubygem-diff-lcs \
		rubygem-mini_mime>=1.1<2:mail/rubygem-mini_mime \
		rubygem-multi_test>=1.1<2:devel/rubygem-multi_test \
		rubygem-sys-uname>=1.2<2:sysutils/rubygem-sys-uname

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber

PORTSCOUT=	limit:^9\.

.include <bsd.port.mk>
