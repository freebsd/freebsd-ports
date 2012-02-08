# New ports collection makefile for:	xapian-bindings
# Date created:		2007-05-26
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	xapian-bindings
PORTVERSION=	1.2.7
CATEGORIES=	databases
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bindings allowing Xapian to be used from various programming languages

LIB_DEPENDS=	xapian.26:${PORTSDIR}/databases/xapian-core

LICENSE=	GPLv2

OPTIONS=	PHP     "Build PHP binding" on \
		PYTHON  "Build Python binding" on \
		RUBY    "Build Ruby binding" on

CONFIGURE_ARGS=	--datarootdir="${DATADIR}" --docdir="${DOCSDIR}" \
		--without-csharp --without-java --without-tcl
GNU_CONFIGURE=	yes

.if defined(WITHOUT_PHP)
CONFIGURE_ARGS+=	--without-php
PLIST_SUB+=	BINDING_PHP="@comment "
.else
CONFIGURE_ARGS+=	--with-php
CONFIGURE_ENV+=	PHP_CONFIG="${LOCALBASE}/bin/php-config"
PLIST_SUB+=	BINDING_PHP=""
USE_PHP=	yes
USE_PHP_BUILD=	yes
.endif

.if defined(WITHOUT_PYTHON)
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	BINDING_PYTHON="@comment "
.else
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=	PYTHON_LIB="${PYTHON_SITELIBDIR}"
PLIST_SUB+=	BINDING_PYTHON=""
USE_PYTHON=	yes
.endif

.if defined(WITHOUT_RUBY)
CONFIGURE_ARGS+=	--without-ruby
PLIST_SUB+=	BINDING_RUBY="@comment "
.else
CONFIGURE_ARGS+=	--with-ruby
USE_RUBY_RDOC=	no
PLIST_SUB+=	BINDING_RUBY=""
USE_RUBY=	yes
.endif

post-patch:
# do not install rdoc
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-data-local||' ${WRKSRC}/ruby/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-dist_docdataDATA install-dist_exampledataDATA ||' ${WRKSRC}/php/Makefile.in ${WRKSRC}/python/Makefile.in
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-dist_docdataDATA||; 759 s|install-dist_exampledataDATA ||' ${WRKSRC}/ruby/Makefile.in
.endif

.include <bsd.port.mk>
