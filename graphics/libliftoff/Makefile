PORTNAME=	libliftoff
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Lightweight KMS plane library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		compiler:c11 meson pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	emersion
GL_COMMIT=	378ccb4f84a2473fe73dbdc56fe35a0d2ee661cc

.include <bsd.port.mk>
