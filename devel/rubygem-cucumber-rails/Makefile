# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cucumber-rails
PORTVERSION=	2.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cucumber generator and runtime for Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-capybara>=2.12<4:devel/rubygem-capybara \
		rubygem-cucumber>=3.0.2<4:devel/rubygem-cucumber \
		rubygem-mime-types>=2.0<4:misc/rubygem-mime-types \
		rubygem-nokogiri>=1.8:textproc/rubygem-nokogiri \
		rubygem-railties5>=4.2:www/rubygem-railties5

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	bin/*.sh

.include <bsd.port.mk>
