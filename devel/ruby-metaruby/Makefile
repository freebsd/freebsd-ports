# New ports collection makefile for:	MetaRuby
# Date created:		8 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	metaruby
PORTVERSION=	0.6
CATEGORIES=	devel ruby
MASTER_SITES=	http://hostname.2y.net/~matju/MetaRuby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	MetaRuby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		ChangeLog	Overview	TODO

post-patch:
	${RUBY} -i -ne '%r|^\$$: <<| or print' ${WRKSRC}/samples/*

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
