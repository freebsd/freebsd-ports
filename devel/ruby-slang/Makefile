# New ports collection makefile for:	Ruby-slang (slanglib)
# Date created:		23 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	slang
PORTVERSION=	0.33.a
CATEGORIES+=	devel ruby
MASTER_SITES=	http://kondara.sdri.co.jp/~kikutani/
DISTNAME=	${PORTNAME}lib
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
.if defined(WITH_JAPANESE)
LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang
.else
LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang
.endif
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

INSTALL_TARGET=	site-install
CONFIGURE_ARGS=	--with-slang-include="${LOCALBASE}/include/slang" \
		--with-slang-lib="${LOCALBASE}/lib"

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

EXAMPLES_EN=	fm.rb		smgtest.rb	urlview.rb
EXAMPLES_JA=	pager.rb
DOCS_EN=	README		changes.txt
DOCS_JA=	README.euc

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}ruby-

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/slang/ja
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/ruby/slang/
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/ruby/slang/ja/
.endfor
	${MKDIR} ${PREFIX}/share/doc/ruby/slang/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/slang/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/slang/ja/
.endfor
.endif

.include <bsd.port.post.mk>
