# New ports collection makefile for:	Migemo
# Date created:		19 February 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	migemo
PORTVERSION=	0.32
PORTREVISIUON=	1
PORTEPOCH=	1
CATEGORIES=	japanese elisp
MASTER_SITES=   http://migemo.namazu.org/stable/

MAINTAINER=	nobutaka@FreeBSD.org

.if !defined(EMACS_PORT_NAME)
USE_AUTOMAKE=	yes
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.am ${FILESDIR}/extra-patch-configure.in
PLIST_SUB=	MIGEMO="" ELISP="@comment "
.endif

USE_RUBY=	yes
BUILD_DEPENDS+=	${RUBY_SITELIBDIR}/romkan.rb:${PORTSDIR}/japanese/ruby-romkan \
		${RUBY_SITELIBDIR}/bsearch.rb:${PORTSDIR}/devel/ruby-bsearch
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/romkan.rb:${PORTSDIR}/japanese/ruby-romkan \
		${RUBY_SITELIBDIR}/bsearch.rb:${PORTSDIR}/devel/ruby-bsearch

CONFIGURE_ARGS+=--with-rubydir=${RUBY_SITELIBDIR}

post-install:
.if defined(EMACS_PORT_NAME)
	@${CAT} ${PKGMESSAGE}
.else
	@${MKDIR} -p ${DOCSDIR}
	@${MV} ${PREFIX}/share/migemo/migemo.ja.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
