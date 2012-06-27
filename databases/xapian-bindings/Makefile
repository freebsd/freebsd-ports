# New ports collection makefile for:	xapian-bindings
# Date created:		2007-05-26
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	xapian-bindings
PORTVERSION=	1.2.11
CATEGORIES=	databases
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bindings allowing Xapian to be used from various programming languages

LICENSE=	GPLv2

LIB_DEPENDS=	xapian:${PORTSDIR}/databases/xapian-core

OPTIONS_DEFINE=	DOCS PHP PYTHON RUBY
OPTIONS_DEFAULT=PHP PYTHON RUBY

PORTSCOUT=	limitw:1,even

CONFIGURE_ARGS=	--datarootdir=${DATADIR} --docdir=${DOCSDIR} \
		--without-csharp --without-java --without-tcl
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHP}
CONFIGURE_ARGS+=--with-php
CONFIGURE_ENV+=	PHP_CONFIG="${LOCALBASE}/bin/php-config"
USE_PHP=	yes
USE_PHP_BUILD=	yes
PLIST_SUB+=	BINDING_PHP=""
.else
CONFIGURE_ARGS+=--without-php
PLIST_SUB+=	BINDING_PHP="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=--with-python
CONFIGURE_ENV+=	PYTHON_LIB="${PYTHON_SITELIBDIR}"
USE_PYTHON=	yes
PLIST_SUB+=	BINDING_PYTHON=""
.else
CONFIGURE_ARGS+=--without-python
PLIST_SUB+=	BINDING_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY}
CONFIGURE_ARGS+=--with-ruby
USE_RUBY=	yes
USE_RUBY_RDOC=	no
PLIST_SUB+=	BINDING_RUBY=""
.else
CONFIGURE_ARGS+=--without-ruby
PLIST_SUB+=	BINDING_RUBY="@comment "
.endif

post-patch:
# do not install rdoc
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-data-local||' ${WRKSRC}/ruby/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-dist_docdataDATA install-dist_exampledataDATA ||' ${WRKSRC}/php/Makefile.in ${WRKSRC}/python/Makefile.in
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-dist_docdataDATA||; 760 s|install-dist_exampledataDATA ||' ${WRKSRC}/ruby/Makefile.in
.endif

.include <bsd.port.mk>
