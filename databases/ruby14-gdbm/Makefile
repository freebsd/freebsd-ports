# New ports collection makefile for:	ruby-gdbm
# Date created:		24 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gdbm
PORTVERSION=	1.4.6
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	1.4
PKGNAMEPREFIX=	ruby-
DISTNAME=	ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

WRKSRC=		${WRKDIR}/${DISTNAME}/ext/gdbm
CONFIGURE_ARGS=	--with-opt-dir="${PREFIX}"

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}
RUBY?=		${LOCALBASE}/bin/ruby

DOCDIR=		${PREFIX}/share/doc/ruby
EXAMPLESDIR=	${PREFIX}/share/examples/ruby

do-configure:
	cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
