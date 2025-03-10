PORTNAME=	libpciaccess
PORTVERSION=	0.18.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic PCI access library
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	hwdata>0:misc/hwdata

USES=		tar:xz xorg-cat:lib,meson
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
