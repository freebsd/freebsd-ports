# New ports collection makefile for:	Ruby-BDB
# Date created:		8 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bdb
PORTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
PKGNAMESUFFIX=	${WITH_BDB_VER}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby interface to Sleepycat's Berkeley DB revision 2 or later

USE_BDB=	YES

CONFLICTS=	${PKGNAMEPREFIX}${PORTNAME}[2-4]*

USE_RUBY=		yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDOC=		yes

CONFIGURE_ARGS=	--with-db-include=${BDB_INCLUDE_DIR} \
		--with-db-lib=${BDB_LIB_DIR} \
		--with-db-version=${BDB_LIB_NAME:S/^db//}
INSTALL_TARGET=	site-install

DOCS=	Changes \
	README.en \
	bdb.html \
	bdb.rd \
	docs/*.html \
	docs/*.rd

.include <bsd.port.pre.mk>

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/bdb.so

.if !defined(NOPORTDOCS)
DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	*
.endif
.if !defined(NOPORTEXAMPLES)
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}
PORTEXAMPLES=	*
.endif

post-build:
.if !defined(NOPORTDOCS)
	( cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} rdoc )
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/doc
	(cd ${WRKSRC} && ${INSTALL_MAN} ${DOCS} ${DOCSDIR})
	(cd ${WRKSRC}/docs/doc && ${COPYTREE_SHARE} \* ${DOCSDIR}/doc)
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR} "! -empty")
.endif

regression-test:
	( cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test )

.include <bsd.port.post.mk>
