# Created by: Brad House <brad@monetra.com>
# $FreeBSD$

PORTNAME=	libmonetra
PORTVERSION=	7.0.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.monetra.com/pub/libmonetra/
DISTNAME=	libmonetra-${PORTVERSION}

MAINTAINER=	brad@monetra.com
COMMENT=	Library for credit card processing through Monetra (formerly MCVE)

BROKEN=		unfetchable

GNU_CONFIGURE=	yes
USES=		gmake libtool ssl
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}

.include <bsd.port.mk>
