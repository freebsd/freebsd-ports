# New ports collection makefile for:	Ruby-BDB
# Date created:		8 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bdb
PORTVERSION=	0.3.8
CATEGORIES=	databases ruby
MASTER_SITES=	ftp://moulon.inra.fr/pub/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
.if defined(WITH_BDB4)
PKGNAMESUFFIX=	4
.endif
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

.if defined(WITH_BDB4)
LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4
.else
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
.endif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDOC=		yes

.if defined(WITH_BDB4)
CONFIGURE_ARGS=	--with-db-include-dir="${PREFIX}/include/db4" \
		--with-db-version=4
.else
CONFIGURE_ARGS=	--with-db-include-dir="${PREFIX}/include/db3" \
		--with-db-version=3
.endif
INSTALL_TARGET=	site-install

DOCS=		Changes \
		README.en \
		bdb.html \
		bdb.rd \
		docs/*.html \
		docs/*.rd \
		docs/doc

post-build:
.if !defined(NOPORTDOCS)
	cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} rdoc
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
	${CP} -R ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
