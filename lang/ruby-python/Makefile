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
PKGNAMEPREFIX=	ruby-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		python:${PORTSDIR}/lang/python
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		python:${PORTSDIR}/lang/python

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb; \
	${PERL} -i -pe 's/-lc\b/-lc_r/g' Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/python/Lib
	${MKDIR} ${PREFIX}/share/doc/ruby/python/ja
	cd ${WRKSRC}/examples; find . -exec ${INSTALL_DATA} {} ${PREFIX}/share/examples/ruby/python/{} \;
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${WRKSRC}/doc/* \
		${PREFIX}/share/doc/ruby/python/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${WRKSRC}/doc-ja/* \
		${PREFIX}/share/doc/ruby/python/ja/
.endif

.include <bsd.port.mk>
