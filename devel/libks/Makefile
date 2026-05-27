PORTNAME=	libks
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.11
CATEGORIES=	devel

MAINTAINER=	hayzam@alchemilla.io
COMMENT=	Foundational support library for SignalWire C products
WWW=		https://github.com/signalwire/libks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/copyright

LIB_DEPENDS=	libuuid.so:misc/libuuid

USES=		cmake compiler:c11 localbase pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	signalwire

USE_LDCONFIG=	yes

CMAKE_OFF=	WITH_PACKAGING

DOCSDIR=	${PREFIX}/share/doc/libks2

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

.include <bsd.port.mk>
