# New ports collection makefile for:	Ruby-BDB
# Date created:		8 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bdb
PORTVERSION=	0.2.9
CATEGORIES=	databases ruby
MASTER_SITES=	ftp://moulon.inra.fr/pub/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	db3.2:${PORTSDIR}/databases/db3

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-db-include-dir="${PREFIX}/include/db3" \
		--with-db-lib-dir="${PREFIX}/lib/db3"
INSTALL_TARGET=	site-install

DOCS=		Changes README.en bdb.html bdb.rd docs/*

post-patch:
	${RUBY} -i -pe 'sub /have_library\("db"/, %q:have_library("db3":' ${WRKSRC}/src/extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${CP} -R ${WRKSRC}/examples/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
