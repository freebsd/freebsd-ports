# New ports collection makefile for:	hiredis
# Date created:	   29 December 2010
# Whom:		   Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	hiredis
DISTVERSION=	0.11.0
CATEGORIES=	databases

MAINTAINER=	magik@roorback.net
COMMENT=	Minimalistic C client library for the Redis database

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	antirez
GH_TAGNAME=	v${DISTVERSION}
GH_COMMIT=	0fff0f1

USE_GMAKE=	yes
CFLAGS+=	-fPIC
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^REAL_/s/ \$$(ARCH)//' ${WRKSRC}/Makefile

.include <bsd.port.mk>
