# $FreeBSD$

PORTNAME=	deface
PORTVERSION=	1.0.2
CATEGORIES=	devel rubygems www
MASTER_SITES=	RG

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Customize ERB, Haml and Slim views in a Rails application

LICENSE=	MIT

RUN_DEPENDS=	rubygem-colorize>=0.5.8:${PORTSDIR}/devel/rubygem-colorize \
		rubygem-nokogiri>=1.6.0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-polyglot>=0.3:${PORTSDIR}/devel/rubygem-polyglot \
		rubygem-rails4>=3.1:${PORTSDIR}/www/rubygem-rails4

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
