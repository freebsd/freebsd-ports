# New ports collection makefile for:	Ruby-amstd
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	amstd
PORTVERSION=	1.9.3
CATEGORIES=	devel ruby
MASTER_SITES=	http://www1.u-netsurf.ne.jp/~brew/mine/soft/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

NO_BUILD=	yes

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

DOCS_EN=	README.en
DOCS_JA=	README.ja
MODULES=	bench.rb \
		bug.rb \
		collfrom.rb \
		dispatch.rb \
		errutil.rb \
		extmod.rb \
		fileutils.rb \
		futils.rb \
		gconst.rb \
		getdep.rb \
		info.rb \
		must.rb \
		pipeline.rb \
		rbparams.rb \
		recycle.rb \
		rubyemu.rb \
		strquote.rb \
		symbol.rb \
		timer.rb \
		to_s.rb \
		version.rb

do-install:
	${MKDIR} ${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/amstd
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/lib/amstd/${f} \
			${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/amstd/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/amstd/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/amstd/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/amstd/ja/
.endfor
.endif

.include <bsd.port.mk>
