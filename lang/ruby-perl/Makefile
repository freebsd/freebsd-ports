# New ports collection makefile for:	Ruby-perl
# Date created:		11 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	perl
PORTVERSION=	0.2.5
CATEGORIES=	lang	# ruby
MASTER_SITES=	http://www.bekkoame.ne.jp/~yoshidam/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

INSTALL_TARGET=	site-install

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

USE_PERL5=	yes

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

EXAMPLES=	htmlparse.rb	http.rb		perllib.rb	ping.rb \
		test.rb		xmlparser.rb

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb
	@cd ${WRKSRC}/Ruby; \
	${PERL} Makefile.PL

post-build:
	@cd ${WRKSRC}/Ruby; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE}

post-install:
	@cd ${WRKSRC}/Ruby; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/perl
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${PREFIX}/share/examples/ruby/perl/
.endfor
	${MKDIR} ${PREFIX}/share/doc/ruby/perl/ja
	${INSTALL_DATA} ${WRKSRC}/README.ja ${PREFIX}/share/doc/ruby/perl/ja/
.endif

.include <bsd.port.mk>
