# New ports collection makefile for:	ruby-postgres
# Date created:		19 April 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	postgres
PORTVERSION=	0.6.5
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.postgresql.jp/interfaces/ruby/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	pq.2:${PORTSDIR}/databases/postgresql7

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

.if defined(WITH_OLD_LAYOUT)
CONFIGURE_ARGS=	--with-pgsql-include-dir="${LOCALBASE}/pgsql/include" \
		--with-pgsql-lib-dir="${LOCALBASE}/pgsql/lib"
.else
CONFIGURE_ARGS=	--with-pgsql-include-dir="${LOCALBASE}/include/pgsql"
.endif
INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog README doc/postgres.html
DOCS_JA=	README.jp doc/postgres.jp.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/postgres
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_EXAMPLESDIR}/postgres/
	${MKDIR} ${RUBY_DOCDIR}/postgres/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/postgres/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/postgres/ja/
.endfor
.endif

.include <bsd.port.mk>
