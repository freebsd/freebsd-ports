# $FreeBSD$

PORTNAME=	deface
PORTVERSION=	1.7.0
CATEGORIES=	devel rubygems www
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Customize ERB, Haml and Slim views in a Rails application

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-nokogiri>=1.6:textproc/rubygem-nokogiri \
		rubygem-polyglot>=0:devel/rubygem-polyglot \
		rubygem-rails60>=5.2:www/rubygem-rails60 \
		rubygem-rainbow>=2.1.0:devel/rubygem-rainbow

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
