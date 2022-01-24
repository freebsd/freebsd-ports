# Created by: Gea-Suan Lin <gslin@gslin.org>

PORTNAME=	xapian-bindings
PORTVERSION=	1.4.19
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bindings allowing Xapian to be used from various programming languages

LICENSE=	GPLv2

USES=		metaport

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	LUA PERL PHP PYTHON RUBY
# While switching php DEFAULT OPTION PHP is creating circular
# dependency. For now remove default OPTION PHP
OPTIONS_DEFAULT=LUA PERL PYTHON RUBY

LUA_RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}xapian>=${PORTVERSION}:databases/lua-xapian@${LUA_FLAVOR}
LUA_USES=		lua:run
PERL_RUN_DEPENDS=	p5-Xapian>=${PORTVERSION}:databases/p5-Xapian
PHP_RUN_DEPENDS=	${PHP_PKGNAMEPREFIX}xapian>=${PORTVERSION}:databases/php-xapian@${PHP_FLAVOR}
PHP_USES=		php
PHP_VARS=		IGNORE_WITH_PHP="80 81"
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xapian>=${PORTVERSION}:databases/py-xapian@${PY_FLAVOR}
PYTHON_USES=		python:run
RUBY_RUN_DEPENDS=	${RUBY_PKGNAMEPREFIX}xapian>=${PORTVERSION}:databases/ruby-xapian
RUBY_USE=		RUBY=yes
RUBY_VARS=		RUBY_NO_BUILD_DEPENDS=yes

.include <bsd.port.mk>
