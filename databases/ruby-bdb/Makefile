# New ports collection makefile for:	Ruby-BDB
# Date created:		8 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bdb
PORTVERSION=	0.5.1
CATEGORIES=	databases ruby
MASTER_SITES=	ftp://moulon.inra.fr/pub/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	${WITH_BDB_VER}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby interface to Sleepycat's Berkeley DB revision 2 or later

LIB_DEPENDS=	db${LIB_SUFFIX}:${PORTSDIR}/databases/db${WITH_BDB_VER}

CONFLICTS=	${PKGNAMEPREFIX}${PORTNAME}[2-4]*

.if defined(WITH_BDB2) || defined(WITH_DB2)
WITH_BDB_VER=	2
.elif defined(WITH_BDB3) || defined(WITH_DB3)
WITH_BDB_VER=	3
.elif defined(WITH_BDB4) || defined(WITH_DB4)
WITH_BDB_VER=	4
.elif defined(WITH_BDB41) || defined(WITH_DB41)
WITH_BDB_VER=	41
.elif defined(WITH_BDB42) || defined(WITH_DB42)
WITH_BDB_VER=	42
LIB_SUFFIX=	-4.2
.endif
WITH_BDB_VER?=	4
LIB_SUFFIX?=	${WITH_BDB_VER}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDOC=		yes

CONFIGURE_ARGS=	--with-db-include="${PREFIX}/include/db${WITH_BDB_VER}" \
		--with-db-version=${LIB_SUFFIX}
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

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
	${CP} -R ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.if ${RUBY_VER} >= 1.8
	cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ri-site
.endif
.endif

.include <bsd.port.post.mk>
