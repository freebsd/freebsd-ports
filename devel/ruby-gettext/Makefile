# New ports collection makefile for:	Ruby GetText Package
# Date created:		4 February 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	0.6.1
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.iDaemons.org/pub/distfiles/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-package-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby implementation of the gettext library

BUILD_DEPENDS=	racc:${PORTSDIR}/devel/ruby-racc

USE_GETTEXT=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	racc-runtime
USE_RUBY_SETUP=	yes

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
