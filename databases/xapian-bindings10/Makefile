# New ports collection makefile for:	xapian-bindings10
# Date created:		2007-05-26
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	xapian-bindings10
PORTVERSION=	1.0.23
CATEGORIES=	databases
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/
DISTNAME=	${PORTNAME:S/10$//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bindings allowing Xapian to be used from various programming languages

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05

LICENSE=	GPLv2

RUN_DEPENDS=	xapian-core10>=1.0.22:${PORTSDIR}/databases/xapian-core10
BUILD_DEPENDS:=	${RUN_DEPENDS}

CONFIGURE_ARGS=	--datarootdir="${DATADIR}" --docdir="${DOCSDIR}" \
		--without-csharp --without-java --without-tcl
GNU_CONFIGURE=	yes

.ifdef(WITHOUT_PHP)
CONFIGURE_ARGS+=	--without-php
PLIST_SUB+=	BINDING_PHP="@comment "
.else
BROKEN=		does not compile
CONFIGURE_ARGS+=	--with-php
CONFIGURE_ENV+=	PHP_CONFIG="${LOCALBASE}/bin/php-config"
PLIST_SUB+=	BINDING_PHP=""
USE_PHP=	yes
USE_PHP_BUILD=	yes
.endif

.ifdef(WITHOUT_PYTHON)
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=	BINDING_PYTHON="@comment "
.else
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=	PYTHON_LIB="${PYTHON_SITELIBDIR}"
PLIST_SUB+=	BINDING_PYTHON=""
USE_PYTHON=	yes
.endif

.ifdef(WITHOUT_RUBY)
CONFIGURE_ARGS+=	--without-ruby
PLIST_SUB+=	BINDING_RUBY="@comment "
.else
CONFIGURE_ARGS+=	--with-ruby
USE_RUBY_RDOC=	no
PLIST_SUB+=	BINDING_RUBY=""
USE_RUBY=	yes
.endif

post-install:
.ifdef(NOPORTDOCS)
	${RM} -fr ${DOCSDIR}
.endif
.ifndef(WITHOUT_RUBY)
	${RM} -fr ${DOCSDIR}/ruby/rdocs
.endif

.include <bsd.port.mk>
