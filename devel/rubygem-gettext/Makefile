# New ports collection makefile for:	Ruby GetText Package
# Date created:		4 February 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	0.4.0
CATEGORIES=	devel ruby
MASTER_SITES=	http://home2.highway.ne.jp/mutoh/tools/ruby/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-package-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_RD=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

RUBY_SHEBANG_FILES=	${WRKSRC}/samples/*.rb

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs; ${RUBY} makehtml.rb
	cd ${WRKSRC}/samples; ${RUBY} makemo.rb
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	${CP} -R ${WRKSRC}/docs/* ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
