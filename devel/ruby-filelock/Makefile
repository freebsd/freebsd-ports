# New ports collection makefile for:	Ruby-filelock
# Date created:		22 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	filelock
PORTVERSION=	0.2
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.netlab.co.jp/pub/lang/ruby/contrib/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

INSTALL_TARGET=	site-install

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

DOCS=		README
EXAMPLES=	test.rb	tst1.rb	tst2.rb	tst3.rb	tst4.rb

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/filelock
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${PREFIX}/share/examples/ruby/filelock/
.endfor
	${MKDIR} ${PREFIX}/share/doc/ruby/filelock
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/filelock/
.endfor
.endif

.include <bsd.port.mk>
