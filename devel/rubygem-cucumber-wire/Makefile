PORTNAME=	cucumber-wire
PORTVERSION=	8.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wire protocol plugin for Cucumber
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-wire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-core>=11<16:devel/rubygem-cucumber-core \
		rubygem-cucumber-cucumber-expressions>=14<20:devel/rubygem-cucumber-cucumber-expressions

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
