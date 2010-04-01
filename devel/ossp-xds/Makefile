# New ports collection makefile for:   OSSP xds
# Date created:                22 February 2004
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	xds
PORTVERSION=	0.9.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A generic and extensible framework for serialization

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		xds-config.1
MAN3=		xds.3

check:  build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
