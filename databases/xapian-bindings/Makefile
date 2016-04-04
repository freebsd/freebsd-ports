# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	xapian-bindings
PORTVERSION=	1.2.23
CATEGORIES=	databases
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bindings allowing Xapian to be used from various programming languages

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxapian.so:databases/xapian-core

OPTIONS_DEFINE=	DOCS LUA PHP PYTHON RUBY
OPTIONS_DEFAULT=PHP PYTHON RUBY
OPTIONS_SUB=	yes

PORTSCOUT=	limitw:1,even

CONFIGURE_ARGS=	--datarootdir=${DATADIR} --docdir=${DOCSDIR} \
		--without-csharp --without-java --without-perl --without-tcl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool tar:xz

PORTDOCS=	*

LUA_CONFIGURE_ENV=	LUA="${LUA_CMD}" LUA_INC="${LUA_INCDIR}" LUA_LIB="${LUA_MODLIBDIR}" LUA_SO=.so
LUA_CONFIGURE_WITH=	lua
LUA_USES=		lua
PHP_CONFIGURE_ENV=	PHP_CONFIG=${LOCALBASE}/bin/php-config
PHP_CONFIGURE_WITH=	php
PHP_USE=		PHP=yes PHP_BUILD=yes
PYTHON_CONFIGURE_ENV=	PYTHON_LIB=${PYTHON_SITELIBDIR}
PYTHON_CONFIGURE_WITH=	python
PYTHON_USES=		python:2
RUBY_CONFIGURE_WITH=	ruby
RUBY_USE=		RUBY=yes RUBY_RDOC=no

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||g' ${WRKSRC}/configure
# do not install rdoc
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-data-local||' ${WRKSRC}/ruby/Makefile.in

.include <bsd.port.mk>
