PORTNAME=	libpciaccess
DISTVERSION=	0.19
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic PCI access library
WWW=		https://gitlab.freedesktop.org/xorg/lib/libpciaccess

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	hwdata>0:misc/hwdata

USES=		tar:xz xorg-cat:lib,meson
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
