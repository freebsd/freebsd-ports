# New ports collection makefile for:	RubyUnit
# Date created:		22 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	runit
PORTVERSION=	0.2.4
CATEGORIES=	devel ruby
MASTER_SITES=	http://homepage1.nifty.com/markey/ruby/rubyunit/
PKGNAMEPREFIX=	ruby-
DISTNAME=	${PORTNAME:S/^r/ruby/}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	rd2:${PORTSDIR}/textproc/ruby-rdtool
.endif

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

RUBY_SITELIBDIR?=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}
RUBY_SITEARCHLIBDIR?=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}

BINS=		c2t	runtest
DOCS=		HISTORY	README	ToDo

do-build:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} makehtml.rb
.endif

do-install:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} install.rb
.for f in ${BINS}
	${LN} -sf ${f}.rb ${PREFIX}/bin/${f}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/runit
	${CP} -R ${WRKSRC}/sample/ ${PREFIX}/share/examples/ruby/runit/
	${MKDIR} ${PREFIX}/share/doc/ruby/runit
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/runit/
.endfor
	${CP} -R ${WRKSRC}/doc_en/ ${PREFIX}/share/doc/ruby/runit/
.endif

.include <bsd.port.mk>
