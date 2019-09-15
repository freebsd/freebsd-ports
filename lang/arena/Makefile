# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arena
PORTVERSION=	0.9.13
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.minimalinux.org/arena/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C-like scripting language with automatic memory management

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16

GNU_CONFIGURE=	yes

.if defined(WITH_PCRE)
LIB_DEPENDS+=	libpcre.so:devel/pcre
CONFIGURE_ARGS+=	--enable-pcre
.endif

.include <bsd.port.mk>
