PORTNAME=	xorg-macros
PORTVERSION=	1.20.2
CATEGORIES=	devel x11
DISTNAME=	util-macros-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org development aclocal macros
WWW=		https://gitlab.freedesktop.org/xorg/util/macros/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg-cat:util

NO_ARCH=	yes

MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

PLIST_FILES=	share/aclocal/xorg-macros.m4 \
		libdata/pkgconfig/xorg-macros.pc \
		share/util-macros/INSTALL

.include <bsd.port.mk>
