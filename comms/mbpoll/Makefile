PORTNAME=	mbpoll
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.4
CATEGORIES=	comms

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Command line utility to communicate with ModBus slave (RTU/TCP)
WWW=		https://github.com/epsilonrt/mbpoll

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmodbus.so:comms/libmodbus

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	epsilonrt

CMAKE_ARGS+=	-DLIBMODBUS_LIBRARIES="-lm -lmodbus"

PLIST_FILES+=	bin/mbpoll \
		share/man/man1/mbpoll.1.gz

.include <bsd.port.mk>
