# New ports collection makefile for:	Ruby GetText Package
# Date created:		4 February 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	0.1.2
CATEGORIES=	devel ruby
MASTER_SITES=	http://home2.highway.ne.jp/mutoh/tools/ruby/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-package-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs; ${RUBY} yard2html.rb
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/samples/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/docs/* ${RUBY_DOCDIR}/${PORTNAME}/
.endif

.include <bsd.port.mk>
