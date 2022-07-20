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
USES=		cpe libtool:keepla pathfix
USE_LDCONFIG=	yes
CPE_VENDOR=	libdaemon_project

.include <bsd.port.mk>
