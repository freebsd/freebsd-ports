# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	dnstracer
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Trace a chain of DNS servers to the source

USES=		gmake
USES=		gmake autoreconf
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/dnstracer \
		man/man8/dnstracer.8.gz

OPTIONS_DEFINE=		IPV6

IPV6_CONFIGURE_ENABLE=	--disable-ipv6

BROKEN_sparc64=	fails to build

post-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/
	${INSTALL_MAN} ${WRKSRC}/dnstracer.8 ${STAGEDIR}${PREFIX}/man/man8/dnstracer.8

.include <bsd.port.mk>
