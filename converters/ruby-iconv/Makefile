# New ports collection makefile for:	Ruby-iconv
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	iconv
PORTVERSION=	0.4.2.p3
CATEGORIES=	converters ruby
MASTER_SITES=	http://member.nifty.ne.jp/nokada/archive/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/-pre/}

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	rd2:${PORTSDIR}/textproc/ruby-rdtool
.endif

INSTALL_TARGET=	site-install

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb

.if !defined(NOPORTDOCS)
post-build:
	@cd ${WRKSRC}; \
	rd2 iconv.c > iconv.html
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/iconv
.for f in iconv.html rd.css
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/iconv/
.endfor
.endif

.include <bsd.port.mk>
