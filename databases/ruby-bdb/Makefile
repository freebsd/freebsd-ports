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
#.if defined(WITH_BDB4)
#PKGNAMESUFFIX=	4
#.endif
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

.if defined(WITH_BDB4)
LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4
.else
LIB_DEPENDS=	db3.2:${PORTSDIR}/databases/db3
.endif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

.if defined(WITH_BDB4)
CONFIGURE_ARGS=	--with-db-include-dir="${PREFIX}/include/db4"
.else
CONFIGURE_ARGS=	--with-db-include-dir="${PREFIX}/include/db3"
.endif
INSTALL_TARGET=	site-install

DOCS=		Changes README.en bdb.html bdb.rd docs/*

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
