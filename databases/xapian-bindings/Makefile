PORTNAME=	xapian-bindings
PORTVERSION=	1.4.26
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bindings allowing Xapian to be used from various programming languages
WWW=		https://xapian.org/

LICENSE=	GPLv2

USES=		metaport

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	LUA PERL PHP PYTHON RUBY
OPTIONS_DEFAULT=LUA PERL PHP PYTHON RUBY

LUA_RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}xapian>=${PORTVERSION}:databases/lua-xapian@${LUA_FLAVOR}
LUA_USES=		lua:run
PERL_RUN_DEPENDS=	p5-Xapian>=${PORTVERSION}:databases/p5-Xapian
PHP_RUN_DEPENDS=	${PHP_PKGNAMEPREFIX}xapian>=${PORTVERSION}:databases/php-xapian@${PHP_FLAVOR}
PHP_USES=		php
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xapian>=${PORTVERSION}:databases/py-xapian@${PY_FLAVOR}
PYTHON_USES=		python:run
RUBY_RUN_DEPENDS=	${RUBY_PKGNAMEPREFIX}xapian>=${PORTVERSION}:databases/ruby-xapian
RUBY_USES=		ruby:run

.include <bsd.port.mk>
