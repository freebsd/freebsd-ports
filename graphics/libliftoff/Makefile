PORTNAME=	libliftoff
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Lightweight KMS plane library
WWW=		https://gitlab.freedesktop.org/emersion/libliftoff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		compiler:c11 meson pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	emersion
GL_COMMIT=	40834142e1ab25cf0fc8e5461e51f08562294f11

# https://gitlab.freedesktop.org/emersion/libliftoff/-/issues/75
CFLAGS_armv6=	-Wno-error=sign-compare -Wno-error=sign-conversion
CFLAGS_armv7=	-Wno-error=sign-compare -Wno-error=sign-conversion
CFLAGS_i386=	-Wno-error=sign-compare -Wno-error=sign-conversion
CFLAGS_powerpc=	-Wno-error=sign-compare -Wno-error=sign-conversion

.include <bsd.port.mk>
