# New ports collection makefile for:	Ruby/setup.rb
# Date created:		11 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	setup.rb
PORTVERSION=	2.0.4
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www9.xdsl.ne.jp/~aamine/soft/ \
		http://www.xdsl.ne.jp/Cd/aamine/soft/
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:R}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	doc.en/*
DOCS_JA=	doc.ja/*

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
