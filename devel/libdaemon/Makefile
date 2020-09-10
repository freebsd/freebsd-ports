# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdaemon
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Lightweight C library that eases the writing of UNIX daemons

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFIGURE_ARGS=	--disable-lynx
GNU_CONFIGURE=	yes
USES=		libtool:keepla pathfix
USE_LDCONFIG=	yes

.include <bsd.port.mk>
