# New ports collection makefile for:	xapian-bindings
# Date created:		2007-05-26
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	xapian-bindings
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/

MAINTAINER=	gslin@gslin.org
COMMENT=	Bindings allowing Xapian to be used from various programming languages

RUN_DEPENDS=	xapian-core>=1.0.6:${PORTSDIR}/databases/xapian-core
BUILD_DEPENDS:=	${RUN_DEPENDS}

CONFIGURE_ARGS+=	--datarootdir="${DATADIR}" --docdir="${DOCSDIR}" \
		--without-csharp --without-java --without-ruby --without-tcl
GNU_CONFIGURE=	yes

.ifdef(WITHOUT_PHP)
CONFIGURE_ARGS+=	--without-php
PLIST_SUB+=	BINDING_PHP="@comment "
.else
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

post-install:
.ifdef(NOPORTDOCS)
	${RM} -fr ${DOCSDIR}
.endif

.include <bsd.port.mk>
