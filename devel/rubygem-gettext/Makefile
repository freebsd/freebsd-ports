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

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

RUBY_RD_FILES=	# defined
RUBY_SHEBANG_FILES=	${WRKSRC}/samples/*.rb

post-install: doc-install

.include <bsd.port.mk>

doc-install:
.if !defined(NOPORTDOCS)
.if !defined(RUBY_NO_RD_HTML)
	cd ${WRKSRC}/docs; ${RUBY} makehtml.rb
.endif
	cd ${WRKSRC}/samples; ${RUBY} makemo.rb
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	${CP} -R ${WRKSRC}/docs/* ${RUBY_MODDOCDIR}/
.endif
