# New ports collection makefile for:	Ruby-intl
# Date created:		9 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	intl
PORTVERSION=	0.11
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.page.sannet.ne.jp/hirata-naoto/
PKGNAMEPREFIX=	ruby-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

INSTALL_TARGET=	site-install

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/intl/po/
	${INSTALL_DATA} ${WRKSRC}/hello.rb ${PREFIX}/share/examples/ruby/intl/
	${INSTALL_DATA} ${WRKSRC}/ja.po ${PREFIX}/share/examples/ruby/intl/po/
	${MKDIR} ${PREFIX}/share/doc/ruby/intl/ja
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ruby/intl/
	${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/share/doc/ruby/intl/ja/
.endif

.include <bsd.port.mk>
