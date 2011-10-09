# New ports collection makefile for:	libsigsegv
# Date created:		28 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	libsigsegv
PORTVERSION=	2.10
CATEGORIES=	devel
MASTER_SITES=	GNU/libsigsegv

MAINTAINER=	gaod@hychen.org
COMMENT=	Handling page faults in user mode

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=AWK=$(AWK)

PLIST_FILES=	include/sigsegv.h \
		lib/libsigsegv.a \
		lib/libsigsegv.la \
		lib/libsigsegv.so.2 \
		lib/libsigsegv.so

post-install:
	@${CAT} ${PKGMESSAGE}

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.mk>
