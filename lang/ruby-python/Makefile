# New ports collection makefile for:	Ruby/Python
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION= 	0.3.2
CATEGORIES=	lang ruby python
MASTER_SITES=	http://www.goto.info.waseda.ac.jp/~fukusima/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	site-install

post-configure:
	${PERL} -i -pe 's/-lc\b/-lc_r/g' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/python/Lib
	${MKDIR} ${RUBY_DOCDIR}/python/ja
	cd ${WRKSRC}/examples; find . -exec ${INSTALL_DATA} {} ${RUBY_EXAMPLESDIR}/python/{} \;
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${WRKSRC}/doc/* \
		${RUBY_DOCDIR}/python/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${WRKSRC}/doc-ja/* \
		${RUBY_DOCDIR}/python/ja/
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
.include <bsd.port.post.mk>
