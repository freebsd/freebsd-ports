# New ports collection makefile for:	Ruby-locale
# Date created:		15 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	locale
PORTVERSION=	0.2
CATEGORIES=	devel ruby
MASTER_SITES=	http://kafka.salem.mass.edu/~yashi/ruby/
PKGNAMEPREFIX=	ruby-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

#USE_BZIP2=	yes	# only saves 500 bytes..

INSTALL_TARGET=	site-install

WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/locale
	${INSTALL_DATA} ${WRKSRC}/test.rb ${PREFIX}/share/examples/ruby/locale/
	${MKDIR} ${PREFIX}/share/doc/ruby/locale
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ruby/locale/
.endif

.include <bsd.port.mk>
