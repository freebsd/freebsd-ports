# New ports collection makefile for:    Ruby-MySQL
# Date created:         7 Aug 2000
# Whom:                 Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mysql
PORTVERSION=	2.3.0
CATEGORIES=	databases	# ruby
MASTER_SITES=	http://www.tmtm.org/mysql/ruby/
PKGNAMEPREFIX=	ruby-
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	mysqlclient.6:${PORTSDIR}/databases/mysql322-client
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb

do-install:
	@cd ${WRKSRC}; \
	${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/mysql/ja
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ruby/mysql/
	${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/share/doc/ruby/mysql/ja
.endif

.include <bsd.port.mk>
