# $FreeBSD$

PORTNAME=	deface
PORTVERSION=	1.0.2
CATEGORIES=	devel rubygems www
MASTER_SITES=	RG

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Customize ERB, Haml and Slim views in a Rails application

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-colorize>=0.5.8:devel/rubygem-colorize \
		rubygem-nokogiri>=1.6.0:textproc/rubygem-nokogiri \
		rubygem-polyglot>=0.3:devel/rubygem-polyglot \
		rubygem-rails4>=3.1:www/rubygem-rails4

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
