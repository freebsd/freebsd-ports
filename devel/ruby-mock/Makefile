# New ports collection makefile for:	Ruby/Mock
# Date created:		2 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mock
PORTVERSION=	1.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.b13media.com/dev/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An RUnit extention that makes it very easy to implement Mock Objects

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	runit

NO_BUILD=	yes

post-patch:
	${RUBY} -i -pe 'sub %r{\.\./mock}, "mock"' ${WRKSRC}/demo/*

do-install:
	${INSTALL_DATA} ${WRKSRC}/mock.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
