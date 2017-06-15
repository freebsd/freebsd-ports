# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	dnstracer
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Trace a chain of DNS servers to the source

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_sparc64=	fails to build

USES=		gmake autoreconf
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/dnstracer \
		man/man8/dnstracer.8.gz

OPTIONS_DEFINE=		IPV6

IPV6_CONFIGURE_ENABLE=	ipv6

.include <bsd.port.mk>
