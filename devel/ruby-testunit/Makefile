# New ports collection makefile for:	Lapidary
# Date created:		22 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	testunit
PORTVERSION=	0.1.6
CATEGORIES=	devel ruby
MASTER_SITES=	http://testunit.talbott.ws/packages/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOCS=		ChangeLog README TODO doc
EXAMPLES=	examples/*

.include <bsd.port.pre.mk>

.if exists(${RUBY_SITELIBDIR}/rubyunit.rb) && !exists(${RUBY_SITELIBDIR}/runit/testunit-installed)
PLIST_SUB+=	RUNIT_COMPAT:="@comment "
.else
PLIST_SUB+=	RUNIT_COMPAT:=""
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
