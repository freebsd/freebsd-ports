# New ports collection makefile for:	arena
# Date created:				2006-06-15
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arena
PORTVERSION=	0.9.11
CATEGORIES=	lang
MASTER_SITES=	http://www.minimalinux.org/arena/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	C-like scripting language with automatic memory management

GNU_CONFIGURE=	yes
MAN1=		arena.1

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--enable-pcre
.endif

.include <bsd.port.mk>
