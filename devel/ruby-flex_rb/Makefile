# New ports collection makefile for:	flex_rb
# Date created:		20 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	flex_rb
PORTVERSION=	0.10
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.inf.bme.hu/~pts/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS=		README
EXAMPLES=	examples/*.rb test*.rb

post-patch:
	${RUBY} -i -pe 'gsub /-ansi\b/, ""' ${WRKSRC}/${RUBY_EXTCONF}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/${PORTNAME}/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
