# New ports collection makefile for:    Ng
# Date created:         18 November 1998
# Whom:                 Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	ng
PORTVERSION=	1.4.4
CATEGORIES=	japanese editors
MASTER_SITES=	http://tomato.sakura.ne.jp/~amura/archives/ng/
DISTNAME=	${PORTNAME}-${PORTVERSION}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	ng-1.4.4-replace_bug.patch

MAINTAINER?=	ginga-freebsd@ginganet.org
COMMENT?=	A very light Emacs-clone with Japanese support

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="-ltermcap"
ALL_TARGET=	ng

MYPORTDOCS=	CHANGES.1_3 CHANGES.doc Ng.FAQ Ng.doc Ng.ref Ng.tut \
		README.Ng README.SKG

post-patch:
	@(cd ${WRKSRC}; ${LN} -sf sys/bsd/Makefile . )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/ng
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${PREFIX}/share/doc/ja/ng/${file}.euc-jp
.endfor
.endif

.include <bsd.port.mk>
