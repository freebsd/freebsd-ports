# New ports collection makefile for:	PL/Ruby
# Date created:		28 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	plruby
PORTVERSION=	0.3.8
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	ftp://moulon.inra.fr/pub/ruby/
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	PL/Ruby procedural language for the PostgreSQL database system

LIB_DEPENDS=	pq.3:${PGSQL_PORTDIR}
RUN_DEPENDS=	postgres:${PORTSDIR}/${POSTGRESQL_PORT}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

POSTGRESQL_PORT?=	databases/postgresql7
PGSQL_VERSION?=		73
PGSQL_PORTDIR?=		${PORTSDIR}/${POSTGRESQL_PORT}
PGSQL_WRKSRC_CMD=	cd ${PGSQL_PORTDIR} && ${MAKE} -V WRKSRC

CONFIGURE_ARGS=		--with-pgsql-version="${PGSQL_VERSION}" \
			--with-pgsql-srcinc="`${PGSQL_WRKSRC_CMD}`/src/include" \
			--with-pgsql-include-dir="${LOCALBASE}/include" \
			--with-pgsql-lib="${LOCALBASE}/lib"
#CONFIGURE_ARGS+=	--with-safe-level=0
#CONFIGURE_ARGS+=	--with-main-safe-level=0
#CONFIGURE_ARGS+=	--with-timeout=30
INSTALL_TARGET=	site-install

DOCS=		Changes README.en plruby.html plruby.rd

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

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
	${CP} -R ${WRKSRC}/test/* ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKDIR}/createlang.sql ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
