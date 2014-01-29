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
USES=		gmake

PLIST_FILES=	bin/dnstracer \
		man/man8/dnstracer.8.gz

OPTIONS_DEFINE=		IPV6

IPV6_CONFIGURE_ENABLE=	--disable-ipv6

.include <bsd.port.mk>
