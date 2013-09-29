# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hiredis
PORTVERSION=	0.11.0
CATEGORIES=	databases

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Minimalistic C client library for the Redis database

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	redis
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	0fff0f1

USES=		gmake
MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX}
CFLAGS+=	-fPIC
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^REAL_/s/ \$$(ARCH)//' ${WRKSRC}/Makefile

.include <bsd.port.mk>
