# New ports collection makefile for:	dnstracer
# Date created:				18 January 2002
# Whom:				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	dnstracer
PORTVERSION=	1.8
CATEGORIES=	dns
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Trace a chain of DNS servers to the source

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes

MAN8=		dnstracer.8
PLIST_FILES=	bin/dnstracer

OPTIONS=	IPV6 "With IPv6 support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

.include <bsd.port.post.mk>
