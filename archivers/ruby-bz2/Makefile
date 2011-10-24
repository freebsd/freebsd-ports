# New ports collection makefile for:	Ruby-BZ2
# Date created:		16 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bz2
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	archivers ruby
MASTER_SITES=	ftp://moulon.inra.fr/pub/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Ruby extension to use libbz2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDOC=		yes

INSTALL_TARGET=	site-install

RUBY_RD_FILES=	bz2.rd

DOCS=		Changes \
		README.en \
		${RUBY_RD_FILES} \
		${RUBY_RD_HTML_FILES}

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif

post-build:
.if !defined(NOPORTDOCS)
	cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} rdoc
.endif

post-install: doc-install

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	@(cd  ${WRKSRC}/ && ${COPYTREE_SHARE} "${DOCS}" ${RUBY_MODDOCDIR}/)
	@(cd  ${WRKSRC}/docs/ && ${COPYTREE_SHARE} doc ${RUBY_MODDOCDIR}/)
.endif

.include <bsd.port.post.mk>
