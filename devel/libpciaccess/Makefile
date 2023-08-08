PORTNAME=	libpciaccess
PORTVERSION=	0.17
CATEGORIES=	devel

PATCH_SITES=	https://gitlab.freedesktop.org/xorg/lib/${PORTNAME}/-/commit/
PATCHFILES+=	7f7d12445c3c.patch:-p1 #https://gitlab.freedesktop.org/xorg/lib/libpciaccess/-/merge_requests/27
PATCHFILES+=	4ee437c98c2d.patch:-p1 #https://gitlab.freedesktop.org/xorg/lib/libpciaccess/-/merge_requests/28

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic PCI access library
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg-cat:lib,meson
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
