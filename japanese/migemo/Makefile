# New ports collection makefile for:	Migemo
# Date created:		19 February 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	migemo
PORTVERSION=	0.40
PORTEPOCH=	1
CATEGORIES=	japanese elisp
MASTER_SITES=   http://namazu.org/~satoru/migemo/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	Japanese incremental search tool

.if !defined(EMACS_PORT_NAME)
USE_AUTOMAKE_VER=	14
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.am ${FILESDIR}/extra-patch-configure.in
PLIST_SUB=	MIGEMO="" ELISP="@comment "
.endif

USE_RUBY=	yes
BUILD_DEPENDS+=	${RUBY_SITELIBDIR}/romkan.rb:${PORTSDIR}/japanese/ruby-romkan \
		${RUBY_SITELIBDIR}/bsearch.rb:${PORTSDIR}/devel/ruby-bsearch
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/romkan.rb:${PORTSDIR}/japanese/ruby-romkan \
		${RUBY_SITELIBDIR}/bsearch.rb:${PORTSDIR}/devel/ruby-bsearch

CONFIGURE_ARGS+=--with-rubydir=${RUBY_SITELIBDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "sparc64"
BROKEN=		"Does not compile on !i386 and !sparc64"
.endif

post-install:
.if defined(EMACS_PORT_NAME)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
