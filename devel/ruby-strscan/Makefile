# New ports collection makefile for:	Ruby-strscan
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	strscan
PORTVERSION=	0.5.8
CATEGORIES=	devel	# ruby
MASTER_SITES=	http://www1.u-netsurf.ne.jp/~brew/mine/soft/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}/amstd/info.rb:${PORTSDIR}/devel/ruby-amstd

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

DOCS_EN=	README.en \
		doc.en/changes.html doc.en/index.html \
		doc.en/reference.html doc.en/usage.html
DOCS_JA=	doc.ja/changes.html doc.ja/index.html \
		doc.ja/reference.html doc.ja/usage.html
EXAMPLES=	lib/strscan/scanner.rb

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} setup.rb config

do-build:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} setup.rb setup

do-install:
	${INSTALL_DATA} ${WRKSRC}/ext/strscanso/strscan.so \
		${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}/
	${MKDIR} ${PREFIX}/share/examples/ruby/strscan
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/ruby/strscan/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/strscan/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/strscan/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/strscan/ja/
.endfor
.endif

.include <bsd.port.mk>
