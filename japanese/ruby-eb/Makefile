# New ports collection makefile for:	Ruby EB
# Date created:		6 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	eb
PORTVERSION=	1.4
CATEGORIES=	japanese ruby
MASTER_SITES=	http://www.osk.3web.ne.jp/~nyasu/software/
DISTNAME=	ruby-${PORTNAME}${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	eb.3:${PORTSDIR}/japanese/eb
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

NO_WRKSUBDIR=	yes
CONFIGURE_ARGS=	--with-opt-dir="${LOCALBASE}"
INSTALL_TARGET=	site-install
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}ruby-

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/eb/ja/
	${INSTALL_DATA} ${WRKSRC}/test.rb ${PREFIX}/share/examples/ruby/eb/ja/
	${MKDIR} ${PREFIX}/share/doc/ruby/eb/ja
	${INSTALL_DATA} ${WRKSRC}/eb.html ${PREFIX}/share/doc/ruby/eb/ja/
.endif

.include <bsd.port.post.mk>
