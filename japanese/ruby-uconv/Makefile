# New ports collection makefile for:	Ruby-uconv
# Date created:		9 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	uconv
PORTVERSION=	0.4.10
CATEGORIES=	japanese converters ruby
MASTER_SITES=	http://www.yoshidam.net/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	site-install

EXAMPLES=	euc2unicode.rb \
		test-utf.rb	test-utf2.rb \
		test_euc.txt	test_euc.xml \
		trilang.xml	unicode2euc.rb	xmlconv.rb

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-install:
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${RUBY_MODEXAMPLESDIR}/ja
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.post.mk>
