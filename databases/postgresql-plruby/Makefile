# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	postgresql-plruby
PORTVERSION=	0.5.7
PORTREVISION=	3
CATEGORIES=	databases ruby
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	PL/Ruby procedural language for the PostgreSQL database system

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

BROKEN_powerpc64=	fails to build: ruby.h:628:35: call to 'ruby_safe_level_2_error' declared with attribute error: $SAFE=2 to 4 are obsolete

USES=		uidfix pgsql
WANT_PGSQL=	server
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	devrimgunduz

POSTGRESQL_PORT?=	databases/postgresql${PGSQL_VER_NODOT}-server
PGSQL_PORTDIR?=		${PORTSDIR}/${POSTGRESQL_PORT}
PGSQL_WRKSRC_CMD=	cd ${PGSQL_PORTDIR} && ${MAKE} -V WRKSRC

CONFIGURE_ARGS=		--with-pg-config="${LOCALBASE}/bin/pg_config" \
			--with-pgsql-srcinc="`${PGSQL_WRKSRC_CMD}`/src/include"
#CONFIGURE_ARGS+=	--with-safe-level=0
#CONFIGURE_ARGS+=	--with-main-safe-level=0
#CONFIGURE_ARGS+=	--with-timeout=30
INSTALL_TARGET=	site-install

DOCS=		Changes plruby.html plruby.rd

OPTIONS_DEFINE=	DOCS

PKGMESSAGE=	${WRKDIR}/createlang.sql

post-fetch:
	cd ${PGSQL_PORTDIR} && ${MAKE} -DBATCH patch

post-build:
	${SED} 's,!!PLRUBY_SO!!,${RUBY_SITEARCHLIBDIR}/plruby.so,' \
		${FILESDIR}/createlang.sql > ${WRKDIR}/createlang.sql

post-build-DOCS-on:
	cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} rdoc

post-install:
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKDIR}/createlang.sql ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} docs/doc ${STAGEDIR}${RUBY_MODDOCDIR}/ README.markdown && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${RUBY_MODDOCDIR}/
	${FIND} -ds ${STAGEDIR}${RUBY_MODDOCDIR} -type f -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}

.include <bsd.port.mk>
