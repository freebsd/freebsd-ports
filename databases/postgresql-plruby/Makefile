# New ports collection makefile for:	PL/Ruby
# Date created:		28 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	plruby
PORTVERSION=	0.2.5
CATEGORIES=	databases ruby
MASTER_SITES=	ftp://moulon.inra.fr/pub/ruby/
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	pq.2:${PGSQL_PORTDIR}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

PGSQL_VERSION?=		71
PGSQL_PORTDIR?=		${PORTSDIR}/databases/postgresql7
PGSQL_WRKSRC_CMD=	cd ${PGSQL_PORTDIR} && ${MAKE} -V WRKSRC

CONFIGURE_ARGS=		--with-pgsql-version="${PGSQL_VERSION}" \
			--with-pgsql-srcinc-dir="`${PGSQL_WRKSRC_CMD}`/src/include"
.if defined(WITH_OLD_LAYOUT)
CONFIGURE_ARGS+=
			--with-pgsql-include-dir="${LOCALBASE}/pgsql/include" \
			--with-pgsql-lib-dir="${LOCALBASE}/pgsql/lib"
.else
CONFIGURE_ARGS+=	--with-pgsql-include-dir="${LOCALBASE}/include/pgsql" \
			--with-pgsql-lib="${LOCALBASE}/lib"
.endif

INSTALL_TARGET=	site-install

DOCS=		README.en plruby.html plruby.rd

PKGMESSAGE=	${WRKDIR}/createlang.sql

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
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${CP} -R ${WRKSRC}/test/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${INSTALL_DATA} ${WRKDIR}/createlang.sql ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
