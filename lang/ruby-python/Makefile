# New ports collection makefile for:	Ruby/Python
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	lang ruby python
MASTER_SITES=	http://www.goto.info.waseda.ac.jp/~fukusima/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PYTHON_PORTSDIR}:-DWITHOUT_THREADS

PYTHON_VERSION?=	python1.5

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-python-lib=`cd ${PYTHON_PORTSDIR} && ${MAKE} -V WRKSRC`
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/python
	${CP} -R ${WRKSRC}/examples/ ${RUBY_EXAMPLESDIR}/python/
	${MKDIR} ${RUBY_DOCDIR}/python/ja
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${WRKSRC}/doc/* \
		${RUBY_DOCDIR}/python/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${WRKSRC}/doc-ja/* \
		${RUBY_DOCDIR}/python/ja/
.endif

.include <bsd.port.mk>
