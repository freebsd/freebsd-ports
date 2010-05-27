# New ports collection makefile for:	libsigsegv
# Date created:		28 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	libsigsegv
PORTVERSION=	2.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libsigsegv

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Handling page faults in user mode

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}

check: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.post.mk>
