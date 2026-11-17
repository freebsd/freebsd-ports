PORTNAME=	cucumber-wire
PORTVERSION=	9.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wire protocol plugin for Cucumber
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-wire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-core>=18<22:devel/rubygem-cucumber-core \
		rubygem-cucumber-cucumber-expressions19>=17<20:devel/rubygem-cucumber-cucumber-expressions19

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
