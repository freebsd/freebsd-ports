# New ports collection makefile for:    ruby-postgres
# Version required:     0.5.3
# Date created:         19 April 1999
# Whom:                 Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

DISTNAME=	postgres-0.5.3
PKGNAME=	ruby-postgres-0.5.3
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.netlab.co.jp/pub/lang/ruby/contrib/ \
		ftp://ftp.TokyoNet.AD.JP/pub/misc/ruby/contrib/ \
		ftp://ftp.iij.ad.jp/pub/lang/ruby/contrib/ \
		ftp://blade.nagaokaut.ac.jp/pub/lang/ruby/contrib/ \
		ftp://ftp.krnet.ne.jp/pub/ruby/contrib/ \
		ftp://mirror.nucba.ac.jp/mirror/ruby/contrib/

MAINTAINER=	yasuf@big.or.jp

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	pq.2:${PORTSDIR}/databases/postgresql

WRKSRC=		${WRKDIR}/postgres
CONFIGURE_ARGS+= --with-pgsql-include-dir="${PGDIR}/include" \
		--with-pgsql-lib-dir="${PGDIR}/lib"
PLIST_SUB+=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${PREFIX}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

PGDIR?=		${PREFIX}/pgsql

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS}

post-install:
	${MKDIR} ${PREFIX}/share/examples/ruby/postgres
	${INSTALL_DATA} ${WRKSRC}/psql*.rb ${PREFIX}/share/examples/ruby/postgres
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/postgres
	${INSTALL_DATA} ${WRKSRC}/README* ${WRKSRC}/*.html ${PREFIX}/share/doc/ruby/postgres
.endif

.include <bsd.port.mk>
