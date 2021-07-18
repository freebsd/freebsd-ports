PORTNAME=	libliftoff
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Lightweight KMS plane library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	emersion

.include <bsd.port.mk>
