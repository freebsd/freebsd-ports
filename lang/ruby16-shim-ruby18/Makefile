# New ports collection makefile for:	ruby16-shim-ruby18
# Date created:		5 May 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	shim-ruby18
PORTVERSION=	1.7.2.2002.07.31
CATEGORIES=	lang devel ruby
MASTER_SITES=	http://www.ruby-lang.org/~knu/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	shim-ruby16_18-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_BZIP2=	yes

USE_RUBY=	yes

CONFIGURE_ARGS=	RUBY=${RUBY}
#CONFIGURE_ARGS+= CONFIGURE_ARGS="-- --config-opt=--with-opt-dir=/usr/local"
WRKSRC=		${WRKDIR}/shim/ruby16

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 1.7
IGNORE=		is only for ruby 1.6, ruby ${RUBY_VER} does not need it
.endif

post-extract:
	${MKDIR} ${WRKSRC}/ext-ra
	${MV} ${WRKSRC}/ext/iconv ${WRKDIR}/

pre-install:
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.post.mk>
