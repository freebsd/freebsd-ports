# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	dnstracer
PORTVERSION=	1.9
CATEGORIES=	dns
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Trace a chain of DNS servers to the source

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes

MAN8=		dnstracer.8
PLIST_FILES=	bin/dnstracer

OPTIONS_DEFINE=		IPV6

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--disable-ipv6
.endif

.include <bsd.port.mk>
