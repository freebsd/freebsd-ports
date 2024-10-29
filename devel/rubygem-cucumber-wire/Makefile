PORTNAME=	cucumber-wire
PORTVERSION=	7.0.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wire protocol plugin for Cucumber
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-wire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-core13>=10.1<14:devel/rubygem-cucumber-core13 \
		rubygem-cucumber-cucumber-expressions17>=14<18:devel/rubygem-cucumber-cucumber-expressions17

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
