# New ports collection makefile for:	Imlib2-Ruby
# Date created:		7 April 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	imlib2
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.pablotron.org/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Imlib2 bindings for Ruby

LIB_DEPENDS=	Imlib2.4:${PORTSDIR}/graphics/imlib2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/imlib2.so
DOCSDIR=	${RUBY_MODDOCDIR}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

# XXX: exists untill it will be committed to bsd.port.mk
COPYTREE_SHARE=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
		2>&1) && \
		${CHOWN} -R ${SHAREOWN}:${SHAREGRP} $$1 && \
		${FIND} $$1/ -type d -exec ${CHMOD} 755 {} \; && \
		${FIND} $$1/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;' --

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
