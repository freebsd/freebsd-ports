# New ports collection makefile for:	Migemo
# Date created:		19 February 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	migemo
PORTVERSION=	0.40
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	japanese elisp
MASTER_SITES=   http://namazu.org/~satoru/migemo/ \
		http://people.freebsd.org/~nobutaka/distfiles/:skkdic
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SKKDIC_FILE}.bz2:skkdic
DIST_SUBDIR=    migemo
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	Japanese incremental search tool

.if !defined(EMACS_PORT_NAME)
USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	213
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.am ${FILESDIR}/extra-patch-configure.in
PLIST_SUB=	MIGEMO="" ELISP="@comment "
.endif

USE_RUBY=	yes
BUILD_DEPENDS+=	${RUBY_SITELIBDIR}/romkan.rb:${PORTSDIR}/japanese/ruby-romkan \
		${RUBY_SITELIBDIR}/bsearch.rb:${PORTSDIR}/devel/ruby-bsearch
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/romkan.rb:${PORTSDIR}/japanese/ruby-romkan \
		${RUBY_SITELIBDIR}/bsearch.rb:${PORTSDIR}/devel/ruby-bsearch

CONFIGURE_ARGS+=--with-rubydir=${RUBY_SITELIBDIR}

SKKDIC_FILE=	SKK-JISYO.L-20050618

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Does not compile on ia64"
.endif

post-extract:
.if !defined(EMACS_PORT_NAME)
	${BZIP2_CMD} -cd ${DISTDIR}/${DIST_SUBDIR}/${SKKDIC_FILE}.bz2 > ${WRKSRC}/SKK-JISYO.L
.endif

post-configure:
.if !defined(EMACS_PORT_NAME)
	(cd ${WRKSRC}; ${CAT} SKK-JISYO.L | ${RUBY} migemo-convert.rb > migemo-dict)
.endif

post-install:
.if defined(EMACS_PORT_NAME)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
