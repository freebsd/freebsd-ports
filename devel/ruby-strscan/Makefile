# New ports collection makefile for:	Ruby-strscan
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	strscan
PORTVERSION=	0.5.8
CATEGORIES=	devel ruby
MASTER_SITES=	http://www1.u-netsurf.ne.jp/~brew/mine/soft/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${RUBY_SITELIBDIR}/amstd/info.rb:${PORTSDIR}/devel/ruby-amstd

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

RUBY_SITELIBDIR?=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}
RUBY_SITEARCHLIBDIR?=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}

DOCS_EN=	README.en \
		doc.en/changes.html doc.en/index.html \
		doc.en/reference.html doc.en/usage.html
DOCS_JA=	doc.ja/changes.html doc.ja/index.html \
		doc.ja/reference.html doc.ja/usage.html

post-patch:
	${PERL} -i -ne '/\bstrscan\b/ and print' ${WRKSRC}/lib/PATHCONV
	for d in amstd; do ${RM} -rf ${WRKSRC}/lib/$$d; done

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} setup.rb config

do-build:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} setup.rb setup

do-install:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} setup.rb install
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
