PORTNAME=	libliftoff
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
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
GL_COMMIT=	c4488eeff94f511aa4d93ef93a042e471c1b2705

.include <bsd.port.mk>
