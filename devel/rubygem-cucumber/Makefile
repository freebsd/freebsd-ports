PORTNAME=	cucumber
PORTVERSION=	12.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour Driven Development with elegance and joy
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-base64>=0.2<1:converters/rubygem-base64 \
		rubygem-builder>=3.2<4:devel/rubygem-builder \
		rubygem-cucumber-ci-environment13>=9<14:devel/rubygem-cucumber-ci-environment13 \
		rubygem-cucumber-core>=20<21:devel/rubygem-cucumber-core \
		rubygem-cucumber-cucumber-expressions>=17<21:devel/rubygem-cucumber-cucumber-expressions \
		rubygem-cucumber-html-formatter>=21<25:textproc/rubygem-cucumber-html-formatter \
		rubygem-cucumber-query>=16.1<17:devel/rubygem-cucumber-query \
		rubygem-diff-lcs>=1.5<3.0:textproc/rubygem-diff-lcs \
		rubygem-logger>=1.6<2:devel/rubygem-logger \
		rubygem-mini_mime>=1.1<2:mail/rubygem-mini_mime \
		rubygem-multi_test>=1<4:devel/rubygem-multi_test \
		rubygem-sys-uname>=1.5<2:sysutils/rubygem-sys-uname

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber

.include <bsd.port.mk>
