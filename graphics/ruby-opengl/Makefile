# New ports collection makefile for:	Ruby/OpenGL
# Date created:		24 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	opengl
PORTVERSION=	0.31
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www2.giganet.net/~yoshi/
PKGNAMEPREFIX=	ruby-
DISTNAME=	rbogl
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

USE_MESA=	yes

WRKSRC=		${WRKDIR}/oglmodule
CONFIGURE_ARGS=	--with-ruby-dir="${LOCALBASE}" --with-x11-dir="${X11BASE}"

INSTALL_TARGET=	site-install

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/opengl
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${PREFIX}/share/examples/ruby/opengl/
	${MKDIR} ${PREFIX}/share/doc/ruby/opengl/ja
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/ruby/opengl/
	${INSTALL_DATA} ${WRKSRC}/README.EUC ${PREFIX}/share/doc/ruby/opengl/ja/
.endif

.include <bsd.port.mk>
