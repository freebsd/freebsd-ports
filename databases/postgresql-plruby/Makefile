# New ports collection makefile for:	PL/Ruby
# Date created:		28 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	plruby
PORTVERSION=	0.4.2
CATEGORIES=	databases ruby
MASTER_SITES=	ftp://moulon.inra.fr/pub/ruby/
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	PL/Ruby procedural language for the PostgreSQL database system

BUILD_DEPENDS=	postgres:${PORTSDIR}/${POSTGRESQL_PORT}
LIB_DEPENDS=	pq.3:${PGSQL_PORTDIR}
RUN_DEPENDS=	postgres:${PORTSDIR}/${POSTGRESQL_PORT}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDOC=		yes

POSTGRESQL_PORT?=	databases/postgresql7
PGSQL_VERSION?=		74
PGSQL_PORTDIR?=		${PORTSDIR}/${POSTGRESQL_PORT}
PGSQL_WRKSRC_CMD=	cd ${PGSQL_PORTDIR} && ${MAKE} -V WRKSRC

CONFIGURE_ARGS=		--with-pgsql-version="${PGSQL_VERSION}" \
			--with-pgsql-srcinc="`${PGSQL_WRKSRC_CMD}`/src/include" \
			--with-pgsql-include="${LOCALBASE}/include" \
			--with-pgsql-lib="${LOCALBASE}/lib"
#CONFIGURE_ARGS+=	--with-safe-level=0
#CONFIGURE_ARGS+=	--with-main-safe-level=0
#CONFIGURE_ARGS+=	--with-timeout=30
INSTALL_TARGET=	site-install

DOCS=		Changes README.en plruby.html plruby.rd docs/doc

PKGMESSAGE=	${WRKDIR}/createlang.sql

post-extract:
	${FIND} ${WRKSRC} -name '*~' -delete

post-patch:
	${RUBY} -i -pe 'gsub /test_mklang\.sql/, "../createlang.sql"' \
		${WRKSRC}/test/*/runtest

pre-configure:
	cd ${PGSQL_PORTDIR} && ${MAKE} -DBATCH patch

post-build:
	${SED} 's,!!PLRUBY_SO!!,${RUBY_SITEARCHLIBDIR}/plruby.so,' \
		${FILESDIR}/createlang.sql > ${WRKDIR}/createlang.sql
.if !defined(NOPORTDOCS)
	cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} rdoc
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
	${CP} -R ${WRKSRC}/test/* ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKDIR}/createlang.sql ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
