PORTNAME=	cucumber
PORTVERSION=	9.1.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour Driven Development with elegance and joy
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=3.2.4<4:devel/rubygem-builder \
		rubygem-cucumber-ci-environment>=9.2.0:devel/rubygem-cucumber-ci-environment \
		rubygem-cucumber-core12>=12.0<13:devel/rubygem-cucumber-core12 \
		rubygem-cucumber-cucumber-expressions>=17.0<18:devel/rubygem-cucumber-cucumber-expressions \
		rubygem-cucumber-gherkin26>=24<27:textproc/rubygem-cucumber-gherkin26 \
		rubygem-cucumber-html-formatter>=20.4.0:textproc/rubygem-cucumber-html-formatter \
		rubygem-cucumber-messages22>=19<23:devel/rubygem-cucumber-messages22 \
		rubygem-diff-lcs>=1.5.0<2:textproc/rubygem-diff-lcs \
		rubygem-mini_mime>=1.1.5<2:mail/rubygem-mini_mime \
		rubygem-multi_test>=1.1.0<2:devel/rubygem-multi_test \
		rubygem-sys-uname>=1.2.3<2:sysutils/rubygem-sys-uname

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber

.include <bsd.port.mk>
