PORTNAME=	cucumber
PORTVERSION=	9.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour Driven Development with elegance and joy
WWW=		https://cucumber.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=3.2.4<4:devel/rubygem-builder \
		rubygem-cucumber-ci-environment>=9.2.0<10:devel/rubygem-cucumber-ci-environment \
		rubygem-cucumber-core>=11.0.0<12:devel/rubygem-cucumber-core \
		rubygem-cucumber-cucumber-expressions>=16.1.2<17:devel/rubygem-cucumber-cucumber-expressions \
		rubygem-cucumber-gherkin>=23.0.1<26.2.1:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-html-formatter>=20.4.0<21:textproc/rubygem-cucumber-html-formatter \
		rubygem-cucumber-messages>=18<23:devel/rubygem-cucumber-messages \
		rubygem-diff-lcs>=1.5.0<2:textproc/rubygem-diff-lcs \
		rubygem-mini_mime>=1.1.5<2:mail/rubygem-mini_mime \
		rubygem-multi_test>=1.1.0<2:devel/rubygem-multi_test \
		rubygem-sys-uname>=1.2.3<2:sysutils/rubygem-sys-uname

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber

.include <bsd.port.mk>
