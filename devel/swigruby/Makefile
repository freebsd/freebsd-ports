# New ports collection makefile for:	SWIGRuby
# Date created:		9 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	swigruby
PORTVERSION=	0.4.4
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.goto.info.waseda.ac.jp/~fukusima/ruby/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		swig:${PORTSDIR}/devel/SWIG
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		swig:${PORTSDIR}/devel/SWIG

USE_GMAKE=	YES

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

DOCS_EN=	ChangeLog README
DOCS_JA=	README.ja

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} configure.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/swigruby
	${CP} -R ${WRKSRC}/examples/ ${PREFIX}/share/examples/ruby/swigruby/
	${MKDIR} ${PREFIX}/share/doc/ruby/swigruby/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/swigruby/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/swigruby/ja/
.endfor
.endif

.include <bsd.port.mk>
