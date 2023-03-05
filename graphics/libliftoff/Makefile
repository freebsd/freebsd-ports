PORTNAME=	libliftoff
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
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
GL_COMMIT=	e045589f37835d66e3ffe8130a597bb4eb9ee08f

.include <bsd.port.mk>
