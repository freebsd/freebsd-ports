PORTNAME=	cucumber-rails
PORTVERSION=	2.6.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cucumber generator and runtime for Rails
WWW=		https://github.com/cucumber/cucumber-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-capybara>=2.18<4:devel/rubygem-capybara \
		rubygem-cucumber>=3.2<9:devel/rubygem-cucumber \
		rubygem-mime-types>=3.3<4:misc/rubygem-mime-types \
		rubygem-nokogiri>=1.10<2:textproc/rubygem-nokogiri \
		rubygem-railties5>=5.0<8:www/rubygem-railties5 \
		rubygem-rexml>=3.0<4:textproc/rubygem-rexml \
		rubygem-webrick>=1.7<2:www/rubygem-webrick

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
