# New ports collection makefile for:    ruby-postgres
# Date created:         19 April 1999
# Whom:                 Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	postgres
PORTVERSION=	0.6.1
CATEGORIES=	databases
MASTER_SITES=	http://webclub.kcom.ne.jp/mb/noborus/archive/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	pq.2:${PORTSDIR}/databases/postgresql7

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS+= --with-pgsql-include-dir="${PGDIR}/include" \
		--with-pgsql-lib-dir="${PGDIR}/lib"
PLIST_SUB+=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${PREFIX}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

PGDIR?=		${PREFIX}/pgsql

DOCS_EN=	ChangeLog README doc/postgres.html
DOCS_JA=	README.jp doc/postgres.jp.html

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS}

post-install:
	${MKDIR} ${PREFIX}/share/examples/ruby/postgres
	${INSTALL_DATA} ${WRKSRC}/sample/* ${PREFIX}/share/examples/ruby/postgres/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/postgres/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/postgres/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/postgres/ja/
.endfor
.endif

.include <bsd.port.mk>
