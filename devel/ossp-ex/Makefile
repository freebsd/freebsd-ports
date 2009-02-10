# New ports collection makefile for:	ossp-ex
# Date created:				2003-01-31
# Whom:					Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	ex
PORTVERSION=	1.0.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OSSP ex is a small exception handling library for use in C

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN3=	ex.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

check: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.post.mk>
