# New ports collection makefile for:	Imlib2-Ruby
# Date created:		7 April 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	imlib2
PORTVERSION=	0.5.2
PORTREVISION=	4
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.pablotron.org/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Imlib2 bindings for Ruby

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_EFL=	imlib2

INSTALL_TARGET=	site-install

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/imlib2.so
DOCSDIR=	${RUBY_MODDOCDIR}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${RUBY_MODEXAMPLESDIR})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${RUBY_MODDOCDIR})
	@${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
	@${FIND} ${RUBY_MODEXAMPLESDIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${RUBY_MODEXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
