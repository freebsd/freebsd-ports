# New ports collection makefile for:	Ruby-uconv
# Date created:		9 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	uconv
PORTVERSION=	0.4.4
CATEGORIES=	japanese converters ruby
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.bekkoame.ne.jp/~yoshidam/
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

INSTALL_TARGET=	site-install

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

EXAMPLES=	euc2unicode.rb	test_euc.txt	test_euc.xml \
		trilang.xml	unicode2euc.rb	xmlconv.rb

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb

post-install:
	${MKDIR} ${PREFIX}/share/examples/ruby/uconv/ja
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${PREFIX}/share/examples/ruby/uconv/ja
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/uconv/ja
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ruby/uconv/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${PREFIX}/share/doc/ruby/uconv/ja/
.endif

.include <bsd.port.mk>
